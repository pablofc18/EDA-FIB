#include <iostream>
#include <vector>
using namespace std;

void write(const vector<char>& sol) {
    for (auto& ch:sol) cout << ch;
    cout << endl;
}

void bck(int idx, int n, int c, vector<char>& sol, int count) {
    if (idx == n) write(sol);
    else {
        if (c > 0) {
            sol[idx] = 'b';
            bck(idx+1,n,c-1,sol,count+1);
        }
        if (count > 0) {
            sol[idx] = 's';
            bck(idx+1,n,c+1,sol,count-1);
        }
    }
}

void bck(int n, int c) {
    vector<char> sol(n);
    bck(0,n,c,sol,0);
}

int main() {
    int n,c; cin >> n >> c;
    bck(n,c);
}
