#include <iostream>
#include <vector>
using namespace std;

// vector not empty
void write(const vector<int>& sol) {
    cout << '(' << sol[0];
    for (int i = 1; i < int(sol.size()); ++i) cout << ',' << sol[i];
    cout << ')' << endl;
}

void escriu_permutacions(int n, vector<int> &sol, vector<bool> &vis) {
    // cas base
    if (n == int(sol.size())) {
        write(sol);
    }
    // cas recursiu
    else {
        for (int i = 1; i <= n; ++i) {
            if (not vis[i]) {
                vis[i] = true;
                sol.push_back(i);
                escriu_permutacions(n,sol,vis);
                sol.pop_back();
                vis[i] = false;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> sol;
    vector<bool> vis(n, false);
    escriu_permutacions(n,sol, vis);
}
