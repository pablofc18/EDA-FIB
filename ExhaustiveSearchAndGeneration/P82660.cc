#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void escriu(const vector<int>& nombres, vector<bool>& escollit) {
    cout << '{';
    bool algun_escrit = false;
    for (int i = 0; i < int(escollit.size()); ++i) {
        if (escollit[i]) {
            if (algun_escrit) cout << ",";
            else algun_escrit = true;
            cout << nombres[i];
        }
    }
    cout << '}' << endl;
}

void escriu_solucions(bool &trobat, const vector<int>& nombres, int s, vector<bool>& escollit, int idx, int suma_parcial) {
    //if (suma_parcial > s) return;
    if (idx  == int(escollit.size())) {
        if (suma_parcial == s) {
            trobat = true;
            escriu(nombres,escollit);
        }
    }

    else {
        escollit[idx] = true;
        escriu_solucions(trobat,nombres,s,escollit, idx+1,suma_parcial + nombres[idx]);
        if (not trobat) {
            escollit[idx] = false;
            escriu_solucions(trobat,nombres,s,escollit,idx+1,suma_parcial);
        }
    }

}

void escriu_solucions(bool &trobat, const vector<int>& nombres, int s, int n) {
    vector<bool> escollit(n);
    int suma_parcial = 0;
    int idx = 0;
    escriu_solucions(trobat,nombres,s,escollit,idx,suma_parcial);
}

int main() {
    // Llegim entrada
    int s; cin >> s;
    int n; cin >> n;
    vector<int> nombres(n);
    for (int i = 0; i < n; ++i) cin >> nombres[i];
    sort(nombres.begin(), nombres.end(), greater<int>());
    // Calculo
    bool trobat = false;
    escriu_solucions(trobat,nombres,s,n);
    if (not trobat) cout << "no solution" << endl;
}
