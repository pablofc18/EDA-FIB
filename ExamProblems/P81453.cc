

/*
**
**
** GUD LACK MAI FRIEN
**
**
*/



#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
using namespace std;

typedef vector<vector<int>> Graph;

void print_list(const list<int>& L) {
    bool first = true;
    for (auto it=L.begin(); it != L.end(); ++it) {
        if (first) {
            cout << *it;
            first = false;
        }
        else cout << ' ' << *it;
    }
    cout << endl;
}

// list<int> bfs(const Graph& G, int ini, int fi) {
//     vector<int> seen(G.size(),false);
//     vector<int> p(G.size(),-1);

//     queue<int> Q;
//     Q.push(ini);
//     list<int> L;
//     while (not Q.empty()) {
//         int u = Q.front(); Q.pop();
//         if (not seen[u]) {
//             L.push_back(u);
//             seen[u] = true;
//             for (int i = 0; i < int(G[u].size()); ++i) {
//                 int v = G[u][i];
//                 Q.push(v);
//             }
//         }
//     }
//     return L;
// }


void dfs(const Graph& G, vector<int>& seen, int i, int fi, list<int>& L) {
    if (not seen[i]) {
        seen[i] = true;
        L.push_back(i);
        if (i == fi) return;
        for (int x:G[i]) {
            dfs(G,seen,x,fi,L);
        }
    }
}

void dfs(const Graph& G, int ini, int fi) {
    vector<list<int>> VL(G[ini].size());
    for (int x:G[ini]) {
        vector<int> seen(G.size(),false);
        list<int> L;
        L.push_back(ini);
        dfs(G,seen,x,fi,L);
        //print_list(L);
        VL.push_back(L);
    }
    int siz = 0;
    int pos = 0;
    if (VL.size() > 0) siz = VL[0].size();
    for (uint i = 0; i < VL.size(); ++i) {
        if (VL[i].size() > siz) {
            siz = VL[i].size();
            pos = i;
        }
    }
    print_list(VL[pos]);
}


int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int x, y; cin >> x >> y;
            G[x].push_back(y);
        }
        //print_list(bfs(G,0,n-1));
        dfs(G,0,n-1);

    }
}


// list<int> topological_sort(const Graph& G, int ini, int fi) {
//     int n = G.size();
//     vector<int> ind(n,0);
//     for (int u = 0; u < n; ++u) {
//         for (int i = 0; i < int(G[u].size()); ++i ) {
//             ++ind[G[u][i]];
//         }
//     }

//     stack<int> S;
//     S.push(ini);
//     list<int> L;
//     while (not S.empty()) {
//         int u = S.top();
//         S.pop();
//         L.push_back(u);

//         for (int i = 0; i < int(G[u].size()); ++i) {
//             int v = G[u][i];
//             S.push(v);
//         }
//     }
//     return L;
// }

// void print_list(const list<int>& L) {
//     bool first = true;
//     for (auto it=L.begin(); it != L.end(); ++it) {
//         if (first) {
//             cout << *it;
//             first = false;
//         }
//         else cout << ' ' << *it;
//     }
//     cout << endl;
// }

// int main() {
//     int n, m;
//     while (cin >> n >> m) {
//         Graph G(n);
//         for (int i = 0; i < m; ++i) {
//             int x, y; cin >> x >> y;
//             G[x].push_back(y);
//         }
//         for (int i = 0; i < n; ++i) {
//             sort(G[i].begin(), G[i].end());
//         }

//         // for (int i = 0; i < n; ++i) {
//         //     for (int j = 0; j < int(G[i].size()); ++j) {
//         //         cout << G[i][j] << ' ';
//         //     }
//         //     cout << endl;
//         // }

//         print_list(topological_sort(G,0,n-1));
//     }
// }
