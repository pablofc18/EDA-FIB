#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
using namespace std;

int infinite = numeric_limits<int>::max();
typedef pair<int,int> Arcw;
typedef vector< vector<Arcw> > Graph;

void read_graph(Graph& G, int n, int m) {
    G = Graph(n);
    for (int i = 0; i < m; ++i) {
        int u,v,c; cin >> u >> v >> c;
        G[u].push_back({c,v});
    }
}

Arcw dijkstra(const Graph& G, int x, int y, vector<int>& p) {
    int n = G.size();
    vector<Arcw> d(n,{infinite,0});
    vector<bool> vis(n, false);
    d[x].first = 0;
    p = vector<int>(n,-1);

    priority_queue<Arcw, vector<Arcw>, greater<Arcw> > Q;
    Q.push({0,x});

    while (not Q.empty() and Q.top().second != y) {
        int u = Q.top().second; Q.pop();

        if (not vis[u]) {
            vis[u] = true;

            // if (u == y) {
            //     return d[u];
            // }
            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v].first > d[u].first + c) {
                    d[v].first = d[u].first + c;
                    d[v].second = d[u].second + 1;
                    Q.push({d[v].first, v});
                    p[v] = u;
                }
                else if (d[v].first >= d[u].first + c and d[v].second > d[u].second) {
                    d[v].second = d[u].second + 1;
                    Q.push({d[v].first, v});
                    p[v] = u;
                }
            }
        }
    }
    return d[y];
}

int main() {
    int n,m;
    while (cin>>n>>m) {
        Graph G;
        read_graph(G,n,m);
        vector<int> p;
        int x,y; cin >> x >> y;
        Arcw r = dijkstra(G,x,y,p);
        if (r.first != infinite) {
            // int ns = 0;
            // stack<int> S;
            // while (p[y] != -1) {
            //     S.push(p[y]);
            //     y = p[y];
            //     ++ns;
            // }
            // cout << "cost " << r << ", " << ns << " step(s)" << endl;

            cout << "cost " << r.first << ", " << r.second << " step(s)" << endl;
        }
        else {
            cout << "no path from " << x << " to " << y << endl;
        }
    }
}
