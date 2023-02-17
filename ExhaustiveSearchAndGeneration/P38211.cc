#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> t;
vector<bool> mc;
vector<bool> md1;
vector<bool> md2;

int diag1(int i, int j) { return i+j; }
int diag2(int i, int j) { return n-1+j-i; }

void write() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // cout << (t[i] == j ? 'Q' : '.');
            if (t[i] == j) cout << 'Q';
            else cout << '.';
        }
        cout << endl;
    }
    //cout << endl;
}

bool queens(int i) {
    // cas base
    if (i == n) {
        write();
        return true;
    }
    // cas recursiu
    else {
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[diag1(i,j)] and not md2[diag2(i,j)]) {
                t[i] = j;
                mc[j] = true;
                md1[diag1(i,j)] = true;
                md2[diag2(i,j)] = true;
                if (queens(i+1)) return true;
                mc[j] = false;
                md1[diag1(i,j)] = false;
                md2[diag2(i,j)] = false;
            }
        }
        return false;
    }
}


int main() {
    cin >> n;
    t = vector<int>(n);
    mc = vector<bool>(n, false);
    md1 = md2 = vector<bool>(2*n-1, false);
    if (not queens(0)) cout << "NO SOLUTION" << endl;
}
