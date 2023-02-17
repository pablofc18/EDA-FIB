#include <iostream>
#include <vector>
using namespace std;

// FUMADITA

/*
**16345
**91236
**84567
**77892
**76543
**
**
**
**
*/

typedef vector< vector<int> > Graph;

void read_graph(Graph& G, int n) {
    G = Graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> G[i][j];
}

void dijkstra(const Graph& G) {

}

int main() {
    int n;

    while (cin >> n) {
        Graph G;
        read_graph(G, n);


    }

}
