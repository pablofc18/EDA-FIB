#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<int>> Matrix;
const int inf = numeric_limits<int>::max();

const vector<Pos> dirs = {{0,1}, {-1,0}, {0,-1}, {1,0}};

bool on_border(Pos p, int n) {
    return p.first == 0 or p.first == n-1 or p.second == 0 or p.second == n-1;
}

int dijkstra(const Matrix& M) {
    int n = M.size();
    vector<vector<int>> dist(n,vector<int>(n,inf));
    vector<vector<int>> seen(n,vector<int>(n,0));
    Pos center = {n/2,n/2};
    // starting position dist
    dist[center.first][center.second] = M[center.first][center.second];

    priority_queue<pair<int,Pos>, vector<pair<int,Pos>>, greater<pair<int,Pos>>> Q;
    Q.push({dist[center.first][center.second],center});

    while (not Q.empty()) {
        Pos p = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if (not seen[p.first][p.second]) {
            seen[p.first][p.second] = 1;
            if (on_border(p,n)) return d;
            for (auto d:dirs) {
                Pos npos = {p.first + d.first, p.second + d.second};
                //
                if (dist[p.first][p.second] + M[npos.first][npos.second] < dist[npos.first][npos.second]) {
                    dist[npos.first][npos.second] = dist[p.first][p.second] + M[npos.first][npos.second];
                    Q.push({dist[npos.first][npos.second],npos});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    while (cin >> n) {
        Matrix M(n,vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> M[i][j];
        cout << dijkstra(M) << endl;
    }
}
