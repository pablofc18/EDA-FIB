#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// typedef vector<vector<int>> Graph;

// int main() {
//     int n,m;
//     while (cin >> n >> m) {
//         Graph G(n);
//         for (int i = 0; i < m; ++i) {
//             int u,v,w;
//             cin >> u >> v >> w;
//             --u;--v;
//             g[u].push_back({})

//         }
//     }
// }

typedef pair<int,int> P;
int main(void) {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<P>> g(n);
        for (int k = 0; k < m; ++k) {
            int x, y, c ;
            cin >> x >> y >> c;
            --x;
            --y;
            g[x ].push_back(P(c, y ));
            g[y ].push_back(P(c, x ));
        }
        vector<bool> mkd(n, false);
        mkd[0] = true;
        priority_queue <P, vector<P>, greater<P> > pq;
        for (P x : g [0]) pq.push(x );
        int sz = 1;
        int sum = 0;
        while (sz < n) {
            int c = pq. top (). first ;
            int x = pq. top (). second ;
            pq.pop ();
            if (not mkd[x]) {
                mkd[x] = true;
                for (P y : g[x]) pq.push(y );
                sum += c;
                ++sz;
            }
        }
        cout << sum << endl;
    }
}
