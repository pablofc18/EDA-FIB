#include <iostream>
#include <vector>
using namespace std;

// vector not empty
void write(const vector<string>& sol) {
    cout << '(' << sol[0];
    for (int i = 1; i < int(sol.size()); ++i) cout << ',' << sol[i];
    cout << ')' << endl;
}

void escriu_permutacions(const vector<string>& words, vector<bool>& vis, vector<string>& sol, int n) {
    // cas base
    if (n == int(sol.size())) {
        write(sol);
    }
    // cas recursiu
    else {
        for (int i = 0; i < n; ++i) {
            if (not vis[i]) {
                vis[i] = true;
                sol.push_back(words[i]);
                escriu_permutacions(words,vis,sol,n);
                sol.pop_back();
                vis[i] = false;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<string> sol;
    vector<bool> vis(n);
    escriu_permutacions(words, vis, sol, n);
}
