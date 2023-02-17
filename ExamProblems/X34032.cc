#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<char> VC;
typedef vector<VC> Board;
vector<Pos> dirs = {{-1,-2}, {1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,-1}, {2,1}};

// XX-X-XX
// X-XZX-X
// XXXIXXX
// X-XZX-X
// XX-X-XX

void read_board(Board& B, int f, int c) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> B[i][j];
        }
    }
}

bool pos_ok(int i, int j, const Board& B) {
    return i >= 0 and i < int(B.size()) and j < int(B[0].size()) and j >= 0;
}

// return the num of steps to reach carrot
int bfs_horse(const Board& B, int i, int j) {
    ///cant be more than 5k dist
    vector<vector<int>> dist(B.size(),vector<int>(B[0].size(),5000));
    dist[i][j] = 0;
    queue<Pos> Q;
    Q.push(Pos(i,j));
    while (not Q.empty()) {
        Pos p = Q.front(); Q.pop();
        if (B[p.first][p.second] == 'p') return dist[p.first][p.second];

        for (auto d:dirs) {
            int ni = p.first + d.first;
            int nj = p.second + d.second;
            if (pos_ok(ni,nj,B) and B[ni][nj] != 'X' and dist[ni][nj] == 5000) {
                dist[ni][nj] = dist[p.first][p.second]+1;
                Q.push(Pos(ni,nj));
            }
        }
    }

    return -1;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        Board B = Board(f,VC(c));
        read_board(B, f, c);
        // initial position of the Horse
        int i,j; cin >> i >> j;

        int steps = bfs_horse(B,i-1,j-1);
        if (steps == -1) cout << "no" << endl;
        else cout << steps << endl;
    }
}
