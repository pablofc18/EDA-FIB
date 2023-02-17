#include <iostream>
#include <vector>
using namespace std;

const vector<char> MOVS = { 'd', 'h', 'u' };

void bck(int n, vector<char>& sol, int idx, int& mvs) {
    if (idx == n) {
        for (char& ch:sol) cout << ch;
        cout << endl;
    }
    else {
        for (uint i = 0; i < MOVS.size(); ++i) {
            if (not (MOVS[i] == 'd' and mvs == 0)) {
                sol.push_back(MOVS[i]);
                if (MOVS[i] == 'u') mvs += 1;
                if (MOVS[i] == 'd') mvs -= 1;
                bck(n,sol,idx+1,mvs);
                if (sol.back() == 'u') mvs -= 1;
                if (sol.back() == 'd') mvs += 1;
                sol.pop_back();
            }
        }
    }

}


void bck(int n) {
    vector<char> sol;
    int mvs = 0;
    bck(n,sol,0,mvs);
}

int main() {
    int n; cin >> n;
    bck(n);
}
