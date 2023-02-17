#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
vector<Pos> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
const int infinite = numeric_limits<int>::max();

void read_board(Board& P, int& ii, int& jj) {
    for (uint i = 0; i < P.size(); ++i) {
        for (uint j = 0; j < P[0].size(); ++j) {
            cin >> P[i][j];
            // save initial pos of pacman
            if (P[i][j] == 'I') {
                ii = i; jj = j;
            }
        }
    }
}

bool pos_ok(int i, int j, const Board& P) {
    return i >= 0 and i < int(P.size()) and j >= 0 and j < int(P[0].size());
}

//vector<Pos> dirsALL = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
bool monster(const Board& P, int i, int j) {
    for (auto d:dirs) {
        int ni = i + d.first;
        int nj = j + d.second;
        if (pos_ok(ni,nj,P) and P[ni][nj] == 'M') return true;
    }
    return false;
}

bool path_exists(const Board& B, int i, int j) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), infinite));
    dist[i][j] = 0;

    queue<Pos> Q;
    Q.push(Pos(i,j));

    if (monster(B,i,j)) return false;

    while (not Q.empty()) {
        Pos p = Q.front(); Q.pop();
        for (auto d:dirs) {
            int ni = p.first + d.first;
            int nj = p.second + d.second;
            if (pos_ok(ni,nj,B) and not monster(B,ni,nj) and dist[ni][nj] == infinite) {
                Q.push(Pos(ni,nj));
                dist[ni][nj] = dist[p.first][p.second] + 1;
                if (B[ni][nj] == 'F') return true;
            }

        }
    }
    return false;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        Board B(f, VC(c));
        int i = 0, j = 0;
        read_board(B,i,j); // i and j saves the initial position

        if (path_exists(B,i,j)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}
