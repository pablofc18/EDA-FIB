#include "Player.hh"


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
    const vector<Dir> dirs1 = {Right,Up,Left,Down};
    const vector<Dir> dirs2 = {Left,Down,Right,Up};
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


    /**
     * Play method, invoked once per each round.
     */
    virtual void play () {
      vector<int> alive = alive_units(me());


      for (int id : alive) {

        //zombie
        for (auto d:dirs1) {
          Pos npos = unit(id).pos + d;
          if (ok_waste(npos) and if_cell_zombie(npos)) move(id,d);
        }

        //food
        for (auto d:dirs1) {
          Pos npos = unit(id).pos + d;
          if (cell(npos).food) move(id,d);
        }

        // if unit next to me go kill
        for (auto direc : dirs1) {
          Pos npos = unit(id).pos + direc;
          if (ok_waste(npos)) {
            // if pos ok no waste, no dead and has owner not me go
            if (cell(npos).owner != -1 and cell(npos).owner != me()
                and unit(cell(npos).id).type == Alive) {
              move(id,direc);
            }
          }
        }

        // if one dir around has no owner go for it, pos ok no waste
        Dir direc; bool dir_found = false;
        for (auto d : dirs1) {
          Pos npos = unit(id).pos + d;
          if (ok_waste(npos) and cell(npos).owner == -1) {
            direc = d;
            dir_found = true;
            break;
          }
        }
        if (dir_found) move(id,direc);

        //if unit next to me owned by smn else

        for (auto dir : dirs1) {
          Pos npos = unit(id).pos + dir;
          if (ok_waste(npos)) {
            // if pos ok and probably surrounded by me just move
            move(id,dir);
          }
        }

        //Dir d = dirs2[[random(0,dirs2.size()-1)];

      }


    }



};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
