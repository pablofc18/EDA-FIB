#include <iostream>
#include <vector>
using namespace std;

const vector<char> CH = {'x','y','z'};

void bck(int n, int m, int idx, vector<char>& sol, int count) {
    if (idx == n) {
        for (char& ch:sol) cout << ch;
        cout << endl;
    }
    else {
        for (uint i = 0; i < CH.size(); ++i) {
            bool rep = (idx > 0 and sol[idx-1] == CH[i]);
            int new_count = (rep ? count+1 : 1);
            if (new_count <= m) {
                sol[idx] = CH[i];
                bck(n,m,idx+1,sol,new_count);
            }
        }
    }
}

void bck(int n, int m) {
    vector<char> sol(n);
    int count = 0;
    bck(n,m,0,sol,count);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        bck(n,m);
        cout << string(20,'-') << endl;
    }
}
