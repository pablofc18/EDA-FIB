#include "Player.hh"
#include <queue>
#include <assert.h>
/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME FirstKiller


struct PLAYER_NAME : public Player {

    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
      return new PLAYER_NAME;
    }

    /**
     * Types and attributes for your player can be defined here.
     */
    // VECTOR DIRECTIONS
    const vector<Dir> dirs = {Right,Up,Left,Down};
    //const vector<Dir> dirs2 = {Left,Down,Right,Up};
    //const vector<Dir> dirs3 = {Up,Left,Down,Right};
    //const vector<Dir> dirs4 = {Down,Up,Right,Left};
    const vector<Dir> dirsALL = {Down,DR,Right,RU,Up,UL,Left,LD};
    const vector<Dir> dirsDIAG = {DR,RU,UL,LD};

    // IF ZOMBIE
    bool if_cell_zombie(Pos npos) {
      return unit(cell(npos).id).type == Zombie;
    }
    // POS OK NO WASTE
    bool ok_waste(Pos npos) {
      return pos_ok(npos) and cell(npos).type != Waste;
    }
    // TRUE IF UNIT HALF UP BOARD
    bool unit_board_up(Pos pos) {
      return pos.i <= board_rows()/2;
    }
    // SURROUNDED BY OWN UNITS
    // x o x
    //   x
    bool surr_me_lrd(Pos pos) {
      return cell(pos+Left).owner == me() and cell(pos+Down).owner == me() and cell(pos+Right).owner == me();
    }

    // BFS looking for food returns the position where closest food
    Pos bfs_food(Pos p) {
      // num 100 bc dist cant be more than 60 (dimensions of board)
      vector<vector<int> > dist(board_rows(),vector<int>(board_cols(),100));

      dist[p.i][p.j] = 0;
      queue<Pos> Q;
      Q.push(p);
      while (not Q.empty()) {
        Pos u = Q.front(); Q.pop();
        for (auto d:dirsALL) {
          Pos npos = u+d;
          if (ok_waste(npos) and dist[npos.i][npos.j] == 100) {
            Q.push(npos);
            dist[npos.i][npos.j] = dist[u.i][u.j] + 1;
            if (cell(npos).food and dist[npos.i][npos.j] <= 5) return npos;
          }
        }
      }
      return Pos(-1,-1);
    }

    /////
        // BFS looking for food returns the position where closest food
    Pos bfs_food_round120(Pos p) {
      // num 100 bc dist cant be more than 60 (dimensions of board)
      vector<vector<int> > dist(board_rows(),vector<int>(board_cols(),100));

      dist[p.i][p.j] = 0;
      queue<Pos> Q;
      Q.push(p);
      while (not Q.empty()) {
        Pos u = Q.front(); Q.pop();
        for (auto d:dirsALL) {
          Pos npos = u+d;
          if (ok_waste(npos) and dist[npos.i][npos.j] == 100) {
            Q.push(npos);
            dist[npos.i][npos.j] = dist[u.i][u.j] + 1;
            if (cell(npos).food and dist[npos.i][npos.j]) return npos;
          }
        }
      }
      return Pos(-1,-1);
    }
    /////


    // BFS looking for kill enemy or zombie
    Pos bfs_enemy(Pos p) {
      // num 100 bc dist cant be more than 60 (dimensions of board)
      vector<vector<int> > dist(board_rows(),vector<int>(board_cols(),100));

      dist[p.i][p.j] = 0;
      queue<Pos> Q;
      Q.push(p);
      while (not Q.empty()) {
        Pos u = Q.front(); Q.pop();
        for (auto d:dirsALL) {
          Pos npos = u+d;
          if (ok_waste(npos) and dist[npos.i][npos.j] == 100) {
            Q.push(npos);
            dist[npos.i][npos.j] = dist[u.i][u.j] + 1;
            if (//unit(cell(npos).id).type == Alive and unit(cell(npos).id).player != me() and cell(npos).id == unit(cell(npos).id).id
                cell(npos).owner != me() and cell(npos).owner != -1 and dist[npos.i][npos.j] <= 5) return npos;
          }
        }
      }
      return Pos(-1,-1);
    }

    // BFS looking for blank cells
    Pos bfs_blank(Pos p) {
      // num 100 bc dist cant be more than 60 (dimensions of board)
      vector<vector<int> > dist(board_rows(),vector<int>(board_cols(),100));

      dist[p.i][p.j] = 0;
      queue<Pos> Q;
      Q.push(p);
      while (not Q.empty()) {
        Pos u = Q.front(); Q.pop();
        for (auto d:dirsALL) {
          Pos npos = u+d;
          if (ok_waste(npos) and dist[npos.i][npos.j] == 100) {
            Q.push(npos);
            dist[npos.i][npos.j] = dist[u.i][u.j] + 1;
            if (cell(npos).owner == -1) return npos;
          }
        }
      }
      return Pos(-1,-1);
    }

    // DFS looking for objective
    // vector<Dir> dfs(Pos myp, Pos objp) {
    //   vector<Dir> dirs;
    // }

    /**
     * Play method, invoked once per each round.
     */
    virtual void play () {
      vector<int> alive = alive_units(me());

      for (int id : alive) {

        //if (round() <= 105) {
          //food
          for (auto d:dirs) {
            Pos npos = unit(id).pos + d;
            if (cell(npos).food) move(id,d);
          }

          //zombie
          for (auto d:dirs) {
            Pos npos = unit(id).pos + d;
            if (ok_waste(npos) and if_cell_zombie(npos)) move(id,d);
          }

          // enemy
          for (auto d:dirs) {
            Pos npos = unit(id).pos + d;
            if (cell(npos).owner != me() and cell(npos).owner != -1
                and unit(cell(npos).id).id == cell(npos).id) move(id,d);
          }

          // RETOCAR ESTE ALG !!! ??? ¿¿¿

          // BFS LOOKING FOR FOOD AND MOVE TO IT
          Pos my_pos = unit(id).pos;
          Pos pos_food = bfs_food(my_pos);
          //assert(pos_food != Pos(-1,-1));
          if (pos_food != Pos(-1,-1)) {
            // i
            if (pos_food.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
            else if (pos_food.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
            // j
            if (pos_food.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
            else if (pos_food.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);
          }

          // BFS LOOKING FOR KILL units enemies
          my_pos = unit(id).pos;
          Pos pos_enemy = bfs_enemy(my_pos);
          if (pos_enemy != Pos(-1,-1)) {
            // j
            if (pos_enemy.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
            else if (pos_enemy.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);
            // i
            if (pos_enemy.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
            else if (pos_enemy.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
          }

          // go for blank cells
          my_pos = unit(id).pos;
          Pos pos_blank= bfs_blank(my_pos);
          if (pos_blank != Pos(-1,-1)) {
            // i
            if (pos_blank.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
            else if (pos_blank.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
            // j
            if (pos_blank.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
            else if (pos_blank.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);
          }

          // if no movements go move random
          Dir d = dirs[random(0,3)];
          Pos npos = unit(id).pos + d;
          while (not ok_waste(npos)) {
            d = dirs[random(0,3)];
            npos = unit(id).pos + d;
          }
          move(id,d);
          // end if
        //}

//////////////////////////////////////////////////////////////////

        // // round 105..200
        // else {

        //   //food
        //   for (auto d:dirs) {
        //     Pos npos = unit(id).pos + d;
        //     if (cell(npos).food) move(id,d);
        //   }

        //   //zombie
        //   for (auto d:dirs) {
        //     Pos npos = unit(id).pos + d;
        //     if (ok_waste(npos) and if_cell_zombie(npos)) move(id,d);
        //   }


        //   // enemy
        //   for (auto d:dirs) {
        //     Pos npos = unit(id).pos + d;
        //     if (cell(npos).owner != me() and cell(npos).owner != -1
        //         and unit(cell(npos).id).id == cell(npos).id) {
        //       if (strength(me()) > strength(cell(npos).owner)) {
        //         move(id,d);
        //       }
        //     }
        //   }

        //   // RETOCAR ESTE ALG !!! ??? ¿¿¿

        //   // BFS LOOKING FOR FOOD AND MOVE TO IT
        //   Pos my_pos = unit(id).pos;
        //   Pos pos_food = bfs_food(my_pos);
        //   //assert(pos_food != Pos(-1,-1));
        //   if (pos_food != Pos(-1,-1)) {
        //     // i
        //     if (pos_food.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
        //     else if (pos_food.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
        //     // j
        //     if (pos_food.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
        //     else if (pos_food.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);

        //   }

        //   // go for blank cells
        //   my_pos = unit(id).pos;
        //   Pos pos_blank= bfs_blank(my_pos);
        //   if (pos_blank != Pos(-1,-1)) {
        //     // i
        //     if (pos_blank.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
        //     else if (pos_blank.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
        //     // j
        //     if (pos_blank.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
        //     else if (pos_blank.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);
        //   }

        //   // BFS LOOKING FOR KILL units enemies
        //   my_pos = unit(id).pos;
        //   Pos pos_enemy = bfs_enemy(my_pos);
        //   if (pos_enemy != Pos(-1,-1)) {
        //     // j
        //     if (pos_enemy.j > my_pos.j and ok_waste(my_pos+Right)) move(id,Right);
        //     else if (pos_enemy.j < my_pos.j and ok_waste(my_pos+Left)) move(id,Left);
        //     // i
        //     if (pos_enemy.i > my_pos.i and ok_waste(my_pos+Down)) move(id,Down);
        //     else if (pos_enemy.i < my_pos.i and ok_waste(my_pos+Up)) move(id,Up);
        //   }


        //   // if no movements go move random
        //   Dir d = dirs[random(0,3)];
        //   Pos npos = unit(id).pos + d;
        //   while (not ok_waste(npos)) {
        //     d = dirs[random(0,3)];
        //     npos = unit(id).pos + d;
        //   }
        //   move(id,d);


        //   // end else
        // }


        //end for, alive units
      }

      // end function play
    }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
