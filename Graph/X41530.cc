#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Graph;

void
read_graph(Graph& g, int n, int m) {
  g = Graph(n);
  for (int i = 0; i < m; ++i) {
      int x,y; cin >> x >> y; // intro parella de vertex amb aresta
      g[x].push_back(y);
      g[y].push_back(x);
    }


}

void
found_cicles(const Graph& G, vector<bool>& visited, int i, int node, bool& cicle){
  if (not visited[i]) {
    visited[i] = true;
    for (int j = 0; j < int(G[i].size()); ++j) {
      if (G[i][j] != node) {
        found_cicles(G, visited, G[i][j], i, cicle);
        if (cicle) return;
      }
    }
  }
  else cicle = true;
}

void
dfs(const Graph& G) {
  vector<bool> visited(int(G.size()), false);
  int trees = 0;
  for (int i = 0; i < int(G.size()); ++i) {
    if (not visited[i]) {
      // busca cicle
      bool cicle = false;
      found_cicles(G,visited,i,i,cicle);
      if (cicle) {
        cout << "no" << endl; return;
      }
      else {
        trees++;
      }
    }
  }
  cout << trees << endl;
}


int
main() {
  int n,m;
  while (cin >> n >> m) {
    Graph G;
    read_graph(G, n, m);
    dfs(G);
  }
}
