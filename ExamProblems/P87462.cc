#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
vector<Pos> dirs = {{0,1},{0,-1},{1,0},{-1,0}};


void read_board(Board& P, int& ii, int& jj) {
    for (uint i = 0; i < P.size(); ++i) {
        for (uint j = 0; j < P[0].size(); ++j) {
            cin >> P[i][j];
            // save initial pos of pacman
            if (P[i][j] == 'P') {
                ii = i; jj = j;
            }
        }
    }
}

bool pos_ok(int i, int j, const Board& P) {
    return i >= 1 and i < int(P.size()-1) and j >= 1 and j < int(P[0].size());
}

vector<Pos> dirsALL = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
bool ghost(const Board& P, int i, int j) {
    for (auto d:dirsALL) {
        int ni = i + d.first;
        int nj = j + d.second;
        if (pos_ok(ni,nj,P) and P[ni][nj] == 'F') return true;
    }
    return false;
}

bool search_pellet(const Board& Pacman, int ii, int jj) {
    // dist cant be never > 10000
    vector<vector<int>> dist(Pacman.size(), vector<int>(Pacman[0].size(), 10000));
    dist[ii][jj] = 0;

    queue<Pos> Q;
    Q.push(Pos(ii,jj));

    // if already near a ghost call false
    if (ghost(Pacman,ii,jj)) return false;

    while (not Q.empty()) {
        Pos p = Q.front();
        Q.pop();

        for (auto d:dirs) {
            int ni = p.first + d.first;
            int nj = p.second + d.second;
            if (pos_ok(ni,nj,Pacman) and not ghost(Pacman,ni,nj) and Pacman[ni][nj] != 'X' and dist[ni][nj] == 10000) {
                Q.push(Pos(ni,nj));
                dist[ni][nj] = dist[p.first][p.second] + 1;
                if (Pacman[ni][nj] == 'B') return true;
            }
        }
    }
    return false;
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        Board Pacman = Board(r,VC(c));
        int i = 0, j = 0;
        read_board(Pacman, i, j);

        if (search_pellet(Pacman, i, j)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
