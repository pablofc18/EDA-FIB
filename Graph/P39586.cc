#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int infinite = numeric_limits<int>::max();
typedef pair<int,int> Arcw;
typedef vector< vector<Arcw> > Graph;

void read_graph(Graph& g, int n, int m) {
    g = Graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back(Arcw(c,v));
    }
}

// Arcw dijkstra(const Graph& G, int x, int y) {
//     int n = G.size();
//     vector<Arcw> d(n,Arcw(infinite,0)); // (distance,ways)
//     d[x].first = 0; // dist x = 0 (first one)
//     vector<bool> vis(n,false);
//     priority_queue< Arcw, vector<Arcw>, greater<Arcw> > Q;
//     Q.push(Arcw(0,x));

//     bool first1 = true;
//     while (not Q.empty() and Q.top().second != y) {
//         int u = Q.top().second; Q.pop();

//         if (not vis[u]) {
//             vis[u] = true;

//             for (int i = 0; i < int(G[u].size()); ++i) {
//                 int v = G[u][i].second;
//                 int c = G[u][i].first;
//                 if (d[v].first >= d[u].first + c) {
//                     if (v == y and first1) {
//                         d[y].second++;
//                         first1 = false;
//                     }
//                     else if (v==y and d[y].first == d[u].first + c) d[y].second++;
//                     d[v].first = d[u].first + c;
//                     Q.push(Arcw(d[v].first,v));

//                 }
//                 // else if (d[v].first == d[u].first + c) if (v == y) d[y].second++;
//             }
//         }
//     }
//     return d[y];
// }

void dijkstra(const Graph &g, int inici, vector<int> &p, vector<int> &d,vector<int> &ways){
    int n = g.size();
    p = vector<int>(n,-1);
    d = vector<int>(n,infinite);
    d[inici] = 0;
    ways = vector<int> (n,0);
    ways[inici] = 1;

    vector<bool> vis(n,false);

    priority_queue<Arcw, vector<Arcw>, greater<Arcw> > pq;

    pq.push(Arcw(0,inici));

    while(!pq.empty()){

        int u = pq.top().second;pq.pop();

        if(!vis[u]){

            vis[u] = true;

            for (int i = 0 ; i< int(g[u].size()) ; ++i){

                int c = g[u][i].first;
                int nextnode = g[u][i].second;

                if (d[nextnode] > d[u]+c){
                    ways[nextnode] = ways[u];
                    d[nextnode] = d[u] +c ;
                    p[nextnode] = u;

                    pq.push(Arcw(d[nextnode],nextnode));

                }

                else if (d[nextnode] == d[u]+c){

                    ways[nextnode]+=ways[u];

                }
            }
        }
    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Graph g;
        read_graph(g,n,m);
        int x,y; cin >> x >> y;

        vector<int> p;
        vector<int> d;
        vector<int> ways;
        dijkstra(g,x,p,d,ways);

        if (d[y] == infinite) cout << "no path from " <<x<< " to "<<y<<endl;
        else {
            cout << "cost "<< d[y] << ", "<<ways[y] <<" way(s)"<<endl;
        }

        //
        //Arcw res = dijkstra(g,x,y);

        // if (res.first != infinite) {
        //     cout << "cost " << res.first << ", " << res.second << " way(s)" << endl;
        // }
        // else {
        //     cout << "no path from " << x << " to " << y << endl;
        // }
    }
}
