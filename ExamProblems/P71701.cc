#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> Vec;
typedef vector<Vec> Mat;
// n*n tauler, r reis
int n, r;

void write(const Mat& M) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (M[i][j] ? 'K' : '.');
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void next_pos(int i, int j, int& ni, int& nj) {
    // avança j
    if (j < n-1) { ni = i; nj = j+1; }
    // sino avança la i
    else {
        ni = i + 1;
        nj = 0;
    }
}

bool pos_ok(int i, int j) {
    return (i < n and i >= 0) and (j < n and j >= 0);
}

const int TOT_DIRS = 8;
const vector<int> dirI = { 0, 1, 1, -1, 0, -1, 1, -1 };
const vector<int> dirJ = { 1, 0, 1, 0, -1, -1, -1, 1 };

bool safe(const Mat& M, int i, int j) {
    for (int k = 0; k < TOT_DIRS; ++k) {
       int ii = i + dirI[k];
       int jj = j + dirJ[k];
       if (pos_ok(ii, jj) and M[ii][jj]) return false;
    }
    return true;
}

void kings(Mat& M, int kings_count, int i, int j) {
    if (kings_count == r) write(M);
    else if (i != n) {
       int ni, nj;
       next_pos(i,j,ni,nj);
       if (safe(M,i,j)) {
           M[i][j] = true;
           kings(M, kings_count+1, ni, nj);
       }
       M[i][j] = false;
       kings(M, kings_count, ni, nj);
    }
}

int main() {
    cin >> n >> r;
    Mat M = Mat(n,Vec(n,false));
    kings(M, 0, 0, 0);
}
