#include <iostream>
#include <vector>
using namespace std;

void bck(int n, vector<char>& sol, vector<bool>& seen, int k) {
    // cas base
    if (n == k) {
        for (uint i = 0; i < sol.size(); ++i) cout << sol[i];
        cout << endl;
    }
    // cas recursiu
    else {
        for (int i = 0; i < n; ++i) {
            if (not seen[i] and (k == 0 or 'a'+i != sol[k-1]+1)) {
                seen[i] = true;
                sol[k] = 'a'+i;
                bck(n, sol, seen, k+1);
                //sol.pop_back();
                seen[i] = false;
            }
        }
    }
}

void backtracking_words(int n) {
    vector<char> sol(n, 'a');
    // 27 words alphabet
    vector<bool> seen(n,false);
    bck(n,sol,seen,0);
}

int main() {
    int n; cin >> n;
    backtracking_words(n);
}
