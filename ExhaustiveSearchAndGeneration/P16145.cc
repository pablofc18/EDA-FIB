#include <iostream>
#include <vector>
using namespace std;

vector<int> t;
vector<bool> mc;
vector<bool> md1;
vector<bool> md2;
int n;

int diag1(int i, int j) { return i+j; }
int diag2(int i, int j) { return i-j+n-1; }

int queens(int i, int n) {
    // cas base
    if (i == n) return 1;
    // cas recursiu
    else {
        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[diag1(i,j)] and not md2[diag2(i,j)]) {
                t[i] = j;
                mc[j] = true;
                md1[diag1(i,j)] = true;
                md2[diag2(i,j)] = true;
                res += queens(i+1,n);
                mc[j] = false;
                md1[diag1(i,j)] = false;
                md2[diag2(i,j)] = false;
            }
        }
        return res;
    }
}

int main() {
    cin >> n;
    t = vector<int>(n);
    mc = vector<bool>(n,false);
    md1 = vector<bool> (2*n-1,false);
    md2 = vector<bool>(2*n-1,false);

    cout << queens(0,n) << endl;
}
