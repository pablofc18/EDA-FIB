#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef vector< vector<int> > Graph;

void read_graph(Graph& g, int n, int m) {
    g = Graph (n);
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
}

list<int> topological_sort(Graph& G) {
    int n = G.size();
    vector<int> ind(n,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < int(G[i].size()); ++j) {
            ++ind[G[i][j]];
        }
    }

    priority_queue<int, vector<int>, greater<int>> S;
    for (int i = 0; i < n; ++i) {
        if (ind[i] == 0) S.push(i);
    }

    list<int> L;
    while (not S.empty()) {
        int u = S.top(); S.pop();
        L.push_back(u);
        for (int i = 0; i < int(G[u].size()); ++i) {
            int v = G[u][i];
            if (--ind[v] == 0) S.push(v);
        }
    }

    return L;
}

void imprimir_list(list<int>& L) {
    if (not L.empty()) {
        cout << L.front();
        L.pop_front();
    }
    while (not L.empty()) {
        cout << ' ' << L.front();
        L.pop_front();
    }
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        Graph G/*(n, vector<int>(n,0))*/;
        read_graph(G,n,m);
        list<int> L;
        L = topological_sort(G);
        //	print_graph(G);
        imprimir_list(L);
        cout << endl;
    }

}
