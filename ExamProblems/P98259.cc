#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
const vector<Pos> dirs = {{0,1}, {-1,0}, {0,-1}, {1,0}};
const int infinite = numeric_limits<int>::max();

void read_board(Board& B) {
    for (int i = 0; i < int(B.size()); ++i) {
        for (int j = 0; j < int(B[0].size()); ++j) {
            cin >> B[i][j];
        }
    }
}

bool pos_ok(int i, int j, const Board& B) {
    return i >= 0 and i < int(B.size()) and j >= 0 and j < int(B[0].size());
}

pair<int,int> bfs(const Board& B) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), infinite));
    dist[0][0] = 0;

    // pair pos and persones trobades
    queue<pair<Pos,int>> Q;
    Q.push({Pos(0,0),0});

    if (B[0][0] == 'T') return {0,0};

    Pos result = {-1,-1};

    while (not Q.empty()) {
        Pos p = Q.front().first;
        int persones = Q.front().second;
        if (B[p.first][p.second] == 'T') return {dist[p.first][p.second],persones};
        Q.pop();
        for (auto d : dirs) {
            int ni = p.first + d.first;
            int nj = p.second + d.second;
            // if (pos_ok(ni,nj,B) and B[ni][nj] != '#' and dist[ni][nj] == infinite) {
            //     dist[ni][nj] = dist[p.first][p.second] + 1;
            //     if (B[ni][nj] == 'P') persones++;
            //     Q.push({Pos(ni,nj),persones});

            //     if (B[ni][nj] == 'T') {
            //         result = {dist[ni][nj],persones};
            //     }
            // }

            if (pos_ok(ni,nj,B)) {
                int pers = persones + int(B[ni][nj] == 'P');
                if (dist[ni][nj] == infinite) {
                    Q.push({Pos(ni,nj),pers});
                    dist[ni][nj] = dist[p.first][p.second] + 1;

                }
                else if (dist[ni][nj] == pers and persones < pers) {
                    persones = pers;
                }
            }
        }
    }
    return result;
}

int main() {
    int f,c;
    while (cin >> f >> c) {
        Board B(f,VC(c));
        read_board(B);

        pair<int,int> d = bfs(B);
        if (d.first == -1) cout << "El telecos ha fugit." << endl;
        else cout << d.first << ' ' << d.second << endl;
    }

}
