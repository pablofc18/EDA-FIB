#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

////// !!! v*m[k] !!!

int bt (int k , const VI& m, int x, int sum_par, int max_und) {
    if (sum_par > x or sum_par + max_und < x) return 0;
    if (k == m.size ()) return 1;
    int cnt = 0;
    for (int v = 0; v <= 2; ++v)
        cnt += bt(k+1, m, x, sum_par + v*m[k], max_und - 2*m[k]);
    return cnt ;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        VI m(n);
        int s = 0;
        for (int k = 0; k < n; ++k) {
            cin >> m[k];
            s += m[k];
        }
        cout << bt(0, m, x, 0, 2*s) << endl;
    }
}
