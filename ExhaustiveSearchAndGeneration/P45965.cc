#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& ones) {
    cout << ones[0];
    for (int i = 1; i < int(ones.size()); ++i) {
        cout << ' ' << ones[i];
    }
    cout << endl;
}

void string_of_1(vector<int>& ones, int m, int idx, int z, int u) {
    // cas base
    if (idx == int(ones.size())) {
        write(ones);
    }
    // cas recursiu
    else {
        if (z < int(ones.size()) - m) {
            ones[idx] = 0; string_of_1(ones, m, idx+1, z+1, u);
        }
        if (u < m) {
            ones[idx] = 1; string_of_1(ones, m, idx+1, z, u+1);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> ones(n);
    string_of_1(ones, m, 0, 0, 0);

}
