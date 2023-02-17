#include <iostream>
#include <vector>
using namespace std;

void bck(int idx, int n, const vector<string>& words, vector<string>& sol, vector<int>& seen) {
    if (idx == n) {
        for (const auto& w:sol) cout << w;
        cout << endl;
    }
    else {
        for (int i = 0; i < int(words.size()); ++i) {
            if (not seen[i]) {
                seen[i] = true;
                if (idx == 0 or sol[idx-1][sol[idx-1].size()-1] != words[i][0]) {
                    sol[idx] = words[i];
                    bck(idx+1,n,words,sol,seen);
                }
                seen[i] = false;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    vector<string> sol(n);
    vector<int> seen(n,false);
    bck(0,n,words,sol,seen);
}
