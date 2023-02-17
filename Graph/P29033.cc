#include <iostream>
#include <vector>
using namespace std;

/*
** CASI CUELA -> WA
*/

const vector<pair<int,int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };
typedef vector< vector<int> > Graph;


bool pos_ok(const Graph& G, int f, int c) {
    return (f >= 0 and f < int(G.size()) and c >= 0 and c < int(G[0].size()));
}

Graph read_graph(int n, int m) {
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    return G;
}

bool two_colored(const Graph& G, int u, vector<int>& clrd, int color) {
    if (clrd[u] == -1) {
        clrd[u] = color;
        for (int v : G[u]) {
            if (not two_colored(G,v,clrd,1-color)) return false;
        }
        return true;
    }
    else return clrd[u] == color;
}

bool two_colors(const Graph& G) {
    int n = G.size();
    vector<int> clrd(n,-1); // -1 no , 1 col1, 0 col2
    for (int i = 0; i < n; ++i) {
        if (clrd[i] == -1) {
            if (not two_colored(G,i,clrd,0)) return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph G = read_graph(n,m);
        if (two_colors(G)) cout << "yes" << endl;
        else cout << "no" << endl;
    }


}
