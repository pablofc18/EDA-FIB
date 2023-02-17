#include <iostream>
#include <queue>
#include <limits>
#include <vector>
using namespace std;

typedef pair<int,int> Arcw;
typedef vector<int> VI;
typedef vector<vector<Arcw>> Graph;
const int inf = numeric_limits<int>::max();

int dijkstra(const Graph& G, int a, int b, const VI& z) {
    int n = G.size();
    vector<int> dist(n,inf);
    dist[a] = 0;
    priority_queue<Arcw, vector<Arcw>, greater<Arcw>> Q;
    Q.push({0,a});
    while (not Q.empty()) {
        Arcw p = Q.top(); Q.pop();
        if (p.first == dist[p.second]) {
            if (p.second == b) return dist[p.second];
            for (auto& d:G[p.second]) {
                int w = d.second;
                int v = d.first;
                int dv = dist[p.second] + w + (v == b ? 0 : z[v]);
                if (dist[v] > dv) {
                    dist[v] = dv;
                    Q.push({dist[v],v});
                }
            }
        }
    }
    return -1;
}

int main() {
   int n,m;
   cin >> n >> m;
   VI z(n);
   for (int i = 0; i < n; ++i) {
       cin >> z[i];
   }
   Graph G(n);
   for (int i = 0; i < m; ++i) {
       int u,v,w; cin >> u >> v >> w;
       G[u].push_back({v,w});
       G[v].push_back({u,w});
   }
   int a,b;
   while(cin >> a >> b) {
       int d = dijkstra(G,a,b,z);
       cout << "c(" << a << "," << b << ") = ";
       if (d != -1) cout << d << endl;
       else cout << "+oo" << endl;
   }
}
