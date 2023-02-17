#include <iostream>
#include <vector>
using namespace std;


void bck(const vector<string>& words, vector<string>& sol, vector<bool>& seen) {
    if (sol.size() == words.size()) {
        for (int i = 0; i < int(sol.size()); ++i) {
            cout << sol[i];
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < int(words.size()); ++i) {
            if (not seen[i] and (int(sol.size()) == 0 or sol[sol.size()-1][sol[sol.size()-1].size()-1] != words[i][0])) {
                seen[i] = true;
                sol.push_back(words[i]);
                //sol[idx] = words[i];
                bck(words, sol, seen);
                sol.pop_back();
                seen[i] = false;
            }
        }
    }
}

void bck(const vector<string>& words, int n) {
    vector<bool> seen(n,false);
    //vector<string> sol(words.size());
    vector<string> sol;
    bck(words,sol,seen);
}

int main() {
    int n; cin >> n;
    int m = n;
    vector<string> words;
    while (m--) {
        string x; cin >> x;
        words.push_back(x);
    }

    bck(words,n);

}
