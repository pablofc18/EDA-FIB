#include <iostream>
#include <vector>
#include <limits>
#include <list>
#include <queue>

using namespace std;

// int infinit = numeric_limits<int>::max();
// vector<pair<int,int> > dirs = {{0,1},{0,-1},{1,0},{-1,0}};

// bool pos_ok(const vector<vector<char> >& T,int f, int c) {
//     return (f >= 0 and f < T.size() and c >= 0 and c < T[0].size());
// }

// // BFS
// int tresor_mes_proper(vector<vector<char> >& T, int f, int c, vector<pair<int,int>> &dirs) {
//     vector<vector<int> > dist(T.size(),vector<int>(T[0].size(),infinit));

//     dist[f][c] = 0;
//     queue<pair<int,int> > Q;
//     Q.push({f,c});
//     vector<pair<int,int>> directions;

//     while (not Q.empty()) {
//         pair<int,int> p = Q.front();
//         Q.pop();
//         int fn = p.first;
//         int cn = p.second;

//         for (auto d : dirs) {
//             int n_f = fn + d.first;
//             int n_c = cn + d.second;
//             directions.push_back(make_pair(n_f,n_c));
//             if (pos_ok(T,n_f,n_c) and T[n_f][n_c] != 'X' and dist[n_f][n_c] == infinit) {
//                 Q.push({n_f,n_c});
//                 dist[n_f][n_c] = dist[fn][cn] + 1;
//                 if (T[n_f][n_c] == 't') {
//                     dirs = directions;
//                     return dist[n_f][n_c];
//                 }
//             }
//         }
//     }
//     return -1;
// }

// int main() {
//     int f,c;
//     cin >> f >> c;
//     vector<vector<char> > T(f,vector<char>(c));
//     for (int i = 0; i < f; ++i)
//         for (int j = 0; j < c; ++j)
//             cin >> T[i][j];
//     int f_ini, c_ini;
//     cin >> f_ini >> c_ini;

//     // Calculo arribabilitat
//     vector<pair<int,int>> dirs;
//     int d = tresor_mes_proper(T,f_ini-1,c_ini-1,dirs);
//     if (d == -1) cout << "no treasure can be reached" << endl;
//     else cout << "minimum distance: " << d << endl;

//     for (int i = 0; i < int(dirs.size()); ++i) {
//         cout << dirs[i].first << " " << dirs[i].second <<  endl;
//     }

// }

typedef  vector< vector<int> > Graph;



list<int> bfs (const Graph& G) {
    int n = G.size();
    list<int> L;
    queue<int> Q;
    vector<bool> enc(n, false);
    for (int u = 0; u < n; ++u) {
        if (not enc[u]) {
            Q.push(u);
            enc[u] = true;
            while (not Q.empty()) {
                int v = Q.front(); Q.pop();
                L.push_back(v);
                for (int w : G[v]) {
                    if (not enc[w]) {
                        Q.push(w); enc[w] = true;
                    }
                }
            }
        }
        return L;
    }
}


int main () {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    list<int> l = bfs(G);
    for (auto i : l) cout << i << " ";
}
