#include <iostream>
#include <vector>
using namespace std;

void write(const vector<char>& sol) {
    for (int i = 0; i < int(sol.size()); ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void bck(int idx, vector<char>& sol, int num_a, int num_b) {
    if (idx == int(sol.size())) write(sol);
    else {
        if (abs((num_a+1)-num_b)<=2) {
            sol[idx] = 'a';
            bck(idx+1,sol,num_a+1,num_b);
        }
        if (abs(num_a-(num_b+1))<=2) {
            sol[idx] = 'b';
            bck(idx+1,sol,num_a,num_b+1);
        }
    }
}

void paraules_compensades(int n) {
    vector<char> sol(n);
    int num_a = 0;
    int num_b = 0;
    bck(0,sol,num_a,num_b);
}

int main() {
    // n in (1..18)
    int n;
    cin >> n;
    paraules_compensades(n);
}
