#include <iostream>
#include <stack>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
typedef vector<vector<Pos>> Path;
const vector<Pos> dirs = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
const int inf = numeric_limits<int>::max();

void read_board(Board& B, Pos& ini) {
    for (int i = 0; i < int(B.size()); ++i) {
        for (int j = 0; j < int(B[0].size()); ++j) {
            cin >> B[i][j];
            if (B[i][j] == 'K') ini = Pos(i,j);
        }
    }
}

bool ok_pos(Pos p, const Board& B) {
    return p.first > 0 and p.first < int(B.size())-1 and p.second > 0 and p.second < int(B[0].size())-1 and B[p.first][p.second] != 'X';
}

int bfs(const Board& B, Pos ini, Pos& fi, Path& path) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), inf));
    dist[ini.first][ini.second] = 0;

    queue<Pos> Q;
    Q.push(ini);

    while (not Q.empty()) {
        Pos p = Q.front(); Q.pop();

        if (B[p.first][p.second] == 'F') {
            fi = p;
            return dist[p.first][p.second];
        }

        for (auto& d:dirs) {
            Pos npos = {d.first + p.first, d.second + p.second};
            if (ok_pos(npos,B) and dist[npos.first][npos.second] == inf) {
                dist[npos.first][npos.second] = dist[p.first][p.second] + 1;
                Q.push(npos);
                path[npos.first][npos.second] = p;
            }
        }
    }
    return -1;
}

int main() {
    int f,c;
    while (cin >> f >> c) {
        Board B(f,VC(c));
        Pos ini;
        read_board(B,ini);
        Pos fi = {-1,-1};
        Path p = Path(f,vector<Pos>(c,{-1,-1}));
        int d = bfs(B,ini,fi,p);
        if (d == -1) {
            cout << 0 << endl;
        }
        else {
            cout << d+1;

            stack<Pos> S;
            Pos fi_initial = fi;
            while (p[fi.first][fi.second] != Pos(-1,-1)) {
                S.push(p[fi.first][fi.second]);
                fi = p[fi.first][fi.second];
            }

            while (not S.empty()) {
                cout << "  " << S.top().first << " " << S.top().second;
                S.pop();
            }
            cout << "  " << fi_initial.first << " " << fi_initial.second << endl;
        }

    }
}
