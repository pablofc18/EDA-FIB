#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
typedef vector<vector<Pos>> Path;
const vector<Pos> dirs = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
const int inf = numeric_limits<int>::max();

bool ok_pos(Pos p, const Board& B) {
    return p.first > 0 and p.first < int(B.size())-1 and p.second > 0 and p.second < int(B[0].size())-1 and B[p.first][p.second] != 'X';
}

int bfs(const Board& B, Pos ini, Path& p, Pos& fi) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), inf));
    dist[ini.first][ini.second] = 0;

    queue<Pos> Q;
    Q.push(ini);

    while (not Q.empty()) {
        Pos u = Q.front(); Q.pop();

        if (B[u.first][u.second] == 'F') {
            fi = u;
            return dist[u.first][u.second];
        }

        for (const auto& d:dirs) {
            Pos npos = {d.first+u.first, d.second+u.second};
            if (ok_pos(npos,B) and dist[npos.first][npos.second] == inf) {
                dist[npos.first][npos.second] = dist[u.first][u.second] + 1;
                Q.push(npos);
                p[npos.first][npos.second] = u;
            }
        }
    }

    return -1;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        Board B(f,VC(c));
        Pos ini;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> B[i][j];
                if (B[i][j] == 'K') ini = Pos(i,j);
            }
        }
        // declare path vector initialize -1,-1
        Path p = Path(f,vector<Pos>(c, {-1,-1}));
        Pos fi = {-1,-1};
        int dist = bfs(B,ini,p,fi);
        if (dist == -1) {
            cout << 0 << endl;
        }
        else {
            cout << dist+1;
            stack<Pos> S;
            Pos fin = fi;
            while (p[fi.first][fi.second] != Pos(-1,-1)) {
                S.push(p[fi.first][fi.second]);
                fi = p[fi.first][fi.second];
            }

            while (not S.empty()) {
                cout << "  " << S.top().first << " " << S.top().second;
                S.pop();
            }
            cout << "  " << fin.first << " " << fin.second << endl;
        }
    }
}
