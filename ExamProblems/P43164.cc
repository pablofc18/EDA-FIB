#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
const int infinite = numeric_limits<int>::max();

void read_board(Board& B, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> B[i][j];
        }
    }
}

bool pos_ok(const Board& B, int i, int j) {
    return i >= 0 and i < int(B.size()) and j >= 0 and j < int(B[0].size());
}

const vector<Pos> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
int bfs(const Board& B, int i, int j) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), infinite));
    dist[i][j] = 0;

    int max2dist = -1;
    int maxdist = -1;

    queue<Pos> Q;
    Q.push(Pos(i,j));

    //bool found_first_t = false;
    while (not Q.empty())
    {
        Pos p = Q.front(); Q.pop();
        for (auto d:dirs) {
            int ni = p.first + d.first;
            int nj = p.second + d.second;
            if (pos_ok(B,ni,nj) and B[ni][nj] != 'X' and dist[ni][nj] == infinite) {
                dist[ni][nj] = dist[p.first][p.second] + 1;
                Q.push(Pos(ni,nj));
                //if (B[ni][nj] == 't' and not found_first_t) found_first_t = true;
                //else if (B[ni][nj] == 't') return dist[ni][nj];
                if (B[ni][nj] == 't') {
                    dist[ni][nj] = dist[p.first][p.second] + 1;
                    max2dist = maxdist;
                    maxdist = dist[ni][nj];
                }
            }
        }
    }
    return max2dist;
}

int main() {
    int r,c;
    cin >> r >> c;
    Board B = Board(r,VC(c));
    read_board(B,r,c);
    int i,j;
    cin >> i >> j;
    int dist = bfs(B,i-1,j-1);
    if (dist != -1) cout << "second maximum distance: " << dist << endl;
    else cout << "we cannot reach two or more treasures" << endl;
}
