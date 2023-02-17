#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Matrix;
typedef vector<bool> VB;
typedef vector<VB> MatB;
const int DIRS = 4;
const int dirsI[DIRS] = { 0, 1, 0, -1 };
const int dirsJ[DIRS] = { 1, 0, -1, 0 };
typedef pair<int,int> Pos;

void read_matrix(Matrix& M) {
    for (uint i = 0; i < M.size(); ++i) {
        for (uint j = 0; j < M[0].size(); ++j) {
            cin >> M[i][j];
        }
    }
}

bool pos_ok(int i, int j, int n, int m) {
    return i < n and i >= 0 and j < m and j >= 0;
}


void escriu_camins(const Matrix& M, int ii, int jj, MatB& seen, vector<Pos>& res) {
    Pos p = res.back();
    // cas base
    if (p.first == ii and p.second == jj) {
        for (uint k = 0; k < res.size(); ++k) {
            cout << M[res[k].first][res[k].second];
        }
        cout << endl;
    }
    // cas recursiu
    else {
        for (int k = 0; k < DIRS; ++k) {
            int new_i, new_j;
            new_i = p.first + dirsI[k];
            new_j = p.second + dirsJ[k];
            if (pos_ok(new_i, new_j, M.size(), M[0].size()) and not seen[new_i][new_j]) {
                seen[new_i][new_j] = true;
                res.push_back(Pos(new_i,new_j));
                escriu_camins(M,ii,jj,seen,res);
                res.pop_back();
                seen[new_i][new_j] = false;
            }
        }

    }
}

int main() {
    int n,m; cin >> n >> m;
    Matrix M = Matrix(n, VC(m));
    read_matrix(M);
    // pos ini
    int i,j; cin >> i >> j;
    // pos fin
    int ii,jj; cin >> ii >> jj;
    MatB seen = MatB(n,VB(m,false));
    vector<Pos> res;
    res.push_back(Pos(i,j));
    seen[i][j] = true;
    // Calcul solució
    escriu_camins(M,ii,jj,seen,res);
}
