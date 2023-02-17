#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

void read_graph(Graph& G, int m) {
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

int vertex_mes_llunya(const Graph& G) {
    int n = G.size();
    vector<bool> seen(n,false);
    queue<pair<int,int>> Q; // first vertex second dist
    int max_dist = 0;
    int vertex_llunya = 0;
    // for all vertex...
    for (int i = 0; i < n; ++i) {
        if (not seen[i]) {
            Q.push({0,0});
            seen[i] = true;
            while (not Q.empty()) {
                int p = Q.front().first;
                int d = Q.front().second;
                Q.pop();
                for (int j : G[p]) {
                    if (not seen[j]) {
                        seen[j] = true;
                        Q.push({j,d+1});
                        if (d+1 > max_dist) {
                            max_dist = d+1;
                            vertex_llunya = j;
                        }
                        else if (d+1 == max_dist) {
                            if (j < vertex_llunya) vertex_llunya = j;
                        }
                    }
                }
            }
        }
    }
    return vertex_llunya;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        read_graph(G,m);
        int v = vertex_mes_llunya(G);
        cout << v << endl;
    }
}
