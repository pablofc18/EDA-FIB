#include <iostream>
#include <vector>
using namespace std;

/*
**     !!! !!! !!!
*  !!! NOT SOLVED !!!
**     !!! !!! !!!
 */


void poss_jumps(vector<int>& jumps, int m, vector<bool>& seen, int &res, int idx) {
    if (idx == int(jumps.size())) {
        cout << res << endl;
        res = 0;
    }
    else {
        for (int i = 0; i < int(jumps.size()); ++i) {
            seen[i] = true;
            res += jumps[i];
            poss_jumps(jumps,m,seen,res,idx+1);
            jumps[i] = -jumps[i];
            seen[i] = false;
        }
    }

}

void possible_jumps(vector<int>& jumps, int m) {
    int n = jumps.size();
    vector<bool> seen(n,false);
    int res = 0;
    poss_jumps(jumps,m,seen,res,0);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; ++i) {
        cin >> jumps[i];
    }
    possible_jumps(jumps,m);
}
