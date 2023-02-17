#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Board;
typedef pair<int,int> Pos;
const int inf = numeric_limits<int>::max();

const vector<pair<int,int>> dirs = {{-1,-2}, {1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,-1}, {2,1}};

bool ok_pos(Pos p, const Board& B) {
    return p.first >= 0 and p.first < int(B.size()) and p.second >= 0 and p.second < int(B[0].size());
}

int bfs(Board& B, const Pos& ini, const Pos& end) {
    vector<vector<int>> dist(B.size(), vector<int>(B[0].size(),inf));
    dist[ini.first][ini.second] = 0;

    queue<Pos> Q;
    Q.push(ini);

    while (not Q.empty()) {
        Pos p = Q.front();
        Q.pop();

        if (p == end) return dist[p.first][p.second];

        for (auto& d:dirs) {
            Pos npos = {p.first + d.first, p.second + d.second};
            if (ok_pos(npos,B) and dist[npos.first][npos.second] == inf) {
                dist[npos.first][npos.second] = dist[p.first][p.second] + 1;
                Q.push(npos);
            }
        }
    }
    return -1;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Board B(n,vector<int>(m,0));
        int W,L; cin >> W >> L;
        int k; cin >> k;
        vector<pair<int,int>> P(k+1);
        P[0] = {0,0};
        for (int i = 1; i <= k; ++i) {
            int r,c; cin >> r >> c;
            P[i] = {r,c};
        }

        bool stop = false;
        int points = 0;
        int bpts = 0;
        for (int i = 0; not stop and i < k; ++i) {
            int dist = bfs(B,P[i],P[i+1]);
            if (dist == -1) stop = true;
            else {
                points += W;
                points -= L*dist;
                if (points > bpts) bpts = points;
            }
        }

        cout << bpts << endl;


    }
}
