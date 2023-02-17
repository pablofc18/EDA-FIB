#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;
typedef map<string,int> Map;
typedef vector<string> VS;

VS task_ordering(const Graph& G, VI& ind, Map& M, const VS& names) {
    int n = G.size();
    priority_queue<string, VS, greater<string>> Q;
    for (int i = 0; i < n; ++i) if (ind[i] == 0) Q.push(names[i]);

    VS rec;
    while (not Q.empty()) {
        string s = Q.top(); Q.pop();
        rec.push_back(s);
        for (const int& u:G[M[s]]) {
            if (--ind[u] == 0) Q.push(names[u]);
        }
    }
    return rec;
}

int main() {
    int n;
    while (cin >> n) {
        VS names(n);
        Map M;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            names[i] = s;
            M[s] = i;
        }

        Graph G(n);
        VI ind(n,0);
        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            string s1, s2; cin >> s1 >> s2;
            G[M[s1]].push_back(M[s2]);
            ++ind[M[s2]];
        }

        VS rec = task_ordering(G,ind,M,names);
        if (int(rec.size()) != n) cout << "NO VALID ORDERING";
        else for (const auto& s:rec) cout << s;
        cout << endl;

    }
}
