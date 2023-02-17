#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& sol) {
    cout << sol[0];
    for (int i = 1; i < int(sol.size()); ++i) {
        cout << ' ' << sol[i];
    }
    cout << endl;
}

void escriu_permutacions(int n, int idx, vector<int>& solution) {
    // CAS BASE
    if (int(solution.size()) == idx) {
        write(solution);
    }
    // CAS RECURSIU
    else {
        solution[idx] = 0; escriu_permutacions(n, idx+1, solution);
        solution[idx] = 1; escriu_permutacions(n, idx+1, solution);
    }
}

int main() {
    int n; cin >> n;
    vector<int> solution(n);
    escriu_permutacions(n, 0, solution);
}
