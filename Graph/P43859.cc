#include <limits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int infinite = std::numeric_limits<int>::max();
typedef pair<int,int> Arcw; // arc with weight
typedef vector< vector<Arcw> > Graph;

void read_graph(Graph& G, int n, int m) {
    G = Graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        G[u].push_back({c,v});  // adjacent vertex u-v with cost c
    }
}

int dijkstra(const Graph& G, int x, int y) {
    int n = G.size();
    vector<int> d(n, infinite);
    d[x] = 0;
    vector<bool> S(n,false);

    priority_queue<Arcw, vector<Arcw>, greater<Arcw>> Q;
    Q.push(Arcw(0,x));

    while (not Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (not S[u]) {
            S[u] = true;

            if (u == y) return d[u];

            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    Q.push(Arcw(d[v], v));
                }
                // if (v == y) {
                //     return d[v];
                // }
            }
        }
    }

    return -1;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph G;
        read_graph(G,n,m);
        // read the beginning/end of the path we want
        int x, y; cin >> x >> y;

        int res = dijkstra(G,x,y);

        if (res != -1) cout << res << endl;
        else cout << "no path from " << x << " to " << y << endl;
    }
}
