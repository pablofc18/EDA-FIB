#include <iostream>
#include <vector>
using namespace std;

const vector<char> CH = {'x','y','z'};

void bck(int idx, int n, int c, vector<char>& sol, int count) {
    if (idx == n) {
        for (const auto& ch:sol) cout << ch;
        cout << endl;
    }
    else {
        for (int i = 0; i < int(CH.size()); ++i) {
            bool at = idx > 0 and sol[idx-1] == CH[i];
            int ncount = (at ? count+1 : 1);
            if (ncount <= c) {
                sol[idx] = CH[i];
                bck(idx+1,n,c,sol,ncount);
            }
        }
    }
}

void bck(int n, int c) {
    vector<char> sol(n);
    bck(0,n,c,sol,1);
}

int main() {
    int n,c;
    while (cin >> n >> c) {
        bck(n,c);
        cout << string(20,'-') << endl;
    }
}
