#include <iostream>
#include <vector>
using namespace std;

void bck(int idx, int n, int d, vector<bool>& seen, vector<int>& sol) {
    if (idx == n) {
        cout << '(' << sol[0];
        for (int i = 1; i < n; ++i) {
            cout << ',' << sol[i];
        }
        cout << ')' << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (not seen[i] and (idx == 0 or abs(sol[idx-1] - (i+1)) <= d)) {
                seen[i] = true;
                sol[idx] = i+1;
                bck(idx+1,n,d,seen,sol);
                seen[i] = false;
            }
        }
    }
}

void bck(int n, int d) {
    vector<int> sol(n);
    vector<bool> seen(n,false);
    bck(0,n,d,seen,sol);
}

int main() {
    int n, d;
    cin >> n >> d;
    bck(n,d);
}
