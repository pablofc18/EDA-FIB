#include <iostream>
#include <vector>
using namespace std;

void write(const vector<char>& sol) {
    for (const char c : sol) cout << c;
    cout << endl;
}

void escriu_c_v(vector<char>& sol, string c, string v, int n, bool consonant, vector<bool>& vis_c, vector<bool>& vis_v) {
    // cas base
    if (2*n == int(sol.size())) {
        write(sol);
    }
    // cas recursiu
    else {
        for (uint i = 0; i < c.size(); ++i) {
            if (consonant) {
                if (not vis_c[i]) {
                    vis_c[i] = true;
                    sol.push_back(c[i]);
                    escriu_c_v(sol, c, v, n, false, vis_c, vis_v);
                    sol.pop_back();
                    vis_c[i] = false;
                }
            }

            else {
                if (not vis_v[i]) {
                    vis_v[i] = true;
                    sol.push_back(v[i]);
                    escriu_c_v(sol, c, v, n, true, vis_c, vis_v);
                    sol.pop_back();
                    vis_v[i] = false;
                }
            }
        }

    }
}

int main() {
    int n; cin >> n;
    string c, v;
    cin >> c >> v;
    vector<char> sol;
    bool consonant = true;
    vector<bool> vis_c(n,false);
    vector<bool> vis_v(n,false);
    escriu_c_v(sol,c,v,n,consonant,vis_c,vis_v);
}
