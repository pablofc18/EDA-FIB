#include <iostream>
#include <stack>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;
typedef pair<int,int> Pos;
const int inf = numeric_limits<int>::max();
const vector<Pos> dirs = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

bool pos_ok(const Board& B, Pos p) {
    return p.first > 0 and p.first < int(B.size())-1 and p.second > 0 and p.second < int(B[0].size())-1 and B[p.first][p.second] != 'X';
}

void read_board(Board& B, int f, int c, Pos& ini) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> B[i][j];
            if (B[i][j] == 'K') ini = {i,j};
        }
    }
}

int bfs(const Board& B, Pos ini, vector<vector<Pos>>& path, Pos& end) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(), inf));
    dist[ini.first][ini.second] = 0;
    queue<Pos> Q;
    Q.push(ini);

    while (not Q.empty()) {
        Pos p = Q.front(); Q.pop();
        if (B[p.first][p.second] == 'F') {
            end = p;
            return dist[p.first][p.second];
        }

        for (auto& d:dirs) {
            Pos npos = {p.first+d.first, p.second+d.second};
            if (pos_ok(B,npos) and dist[npos.first][npos.second] == inf) {
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
        read_board(B,f,c,ini);
        vector<vector<Pos>> path(f,vector<Pos>(c,Pos(-1,-1)));
        Pos end = {-1,-1};
        int dist = bfs(B,ini,path,end);
        if (dist == -1) {
            cout << 0 << endl;
        }
        else {
            cout << dist+1;
            stack<Pos> S;
            Pos endfinal = end;
            while (path[end.first][end.second] != Pos(-1,-1)) {
                S.push(path[end.first][end.second]);
                end = path[end.first][end.second];
            }
            while (not S.empty()) {
                cout << "  " << S.top().first << " " << S.top().second;
                S.pop();
            }
            cout << "  " << endfinal.first << " " << endfinal.second << endl;
        }
    }
}
