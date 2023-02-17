#include <limits>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int infinite = std::numeric_limits<int>::max();
typedef pair<int,int> Arcw; // arc with weight
typedef vector< vector<Arcw> > Graph;

void read_graph(Graph& G, int n, int m) {
    G = Graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        G[u].push_back({c,v});  // adjacent vertex u-v with cost c
    }
}

void dijkstra(const Graph& G, int x, int y, vector<int>& w, bool& found) {
    int n = G.size();
    vector<int> d(n, infinite);
    d[x] = 0;
    vector<bool> S(n,false);

    priority_queue<Arcw, vector<Arcw>, greater<Arcw>> Q;
    Q.push(Arcw(0,x));

    //w.push_back(x);
    while (not Q.empty() and Q.top().second != y) {
        int u = Q.top().second;
        Q.pop();
        if (not S[u]) {
            S[u] = true;

            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    Q.push(Arcw(d[v], v));
                    w[v] = u;
                }
            }
        }
    }
    if (Q.top().second != y) found = false;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph G;
        read_graph(G,n,m);
        // read the beginning/end of the path we want
        int x, y; cin >> x >> y;

        bool found = true;
        vector<int> v(n, -1);
        dijkstra(G,x,y,v, found);

        int y_ini = y;
        stack<int> s;
        // this means no path
        if (not found) {
            cout << "no path from " << x << " to " << y << endl;
        }
        // if path exists
        else {
            while (v[y] != -1) {
                s.push(v[y]);
                y = v[y];
            }
            while (not s.empty()) {
                cout << s.top() << " "; s.pop();
            }
            cout << y_ini << endl;
            }
        }
    }
