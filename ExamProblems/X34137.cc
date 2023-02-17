#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

void dfs(int u, const Graph& G, VI& vis) {
    if (not vis[u]) {
        vis[u] = true;
        for (int g : G[u]) dfs(g,G,vis);
    }
}

int main() {
    int n,u,v,m;
    while (cin >> n >> u >> v >> m) {
        Graph G(n);
        Graph I(n);
        for (int i = 0; i < m; ++i) {
            int x,y; cin >> x >> y;
            G[x].push_back(y);
            I[y].push_back(x);
        }

        VI fwd(n,false);
        dfs(u,G,fwd);
        if (not fwd[v]) cout << 0 << endl;
        else {
            VI bwd(n,false);
            dfs(v,I,bwd);
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += (fwd[k] and bwd[k]);
            }
            cout << sum-2 << endl;
        }

    }
}
