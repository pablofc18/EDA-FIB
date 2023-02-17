#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'u' or ch == 'o';
}

void bck(int n, int idx, vector<char>& sol, const vector<char>& letters) {
    if (idx == n) {
        for (char& ch:sol) cout << ch;
        cout << endl;
    }
    else {
        for (char ch : letters) {
            if (not is_vowel(ch) or idx == 0 or not is_vowel(sol[idx-1])) {
                sol[idx] = ch;
                bck(n,idx+1,sol,letters);
            }
        }
    }
}

void bck(int n, const vector<char>& letters) {
    vector<char> sol(n);
    bck(n,0,sol,letters);
}

int main() {
    int n;
    while (cin >> n) {
        int m; cin >> m;
        vector<char> letters(m);
        for (int i = 0; i < m; ++i) cin >> letters[i];
        sort(letters.begin(), letters.end());
        bck(n,letters);
        cout << string(10,'-') << endl;
    }
}
