#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

typedef vector<string> VS;
typedef vector<pair<pair<int,int>,string>> Vpair;
typedef vector<VS> Matrix;
const int inf = numeric_limits<int>::max();
const vector<pair<int,int>> dirs = {{0,1},{-1,0},{0,-1},{1,0}};

void read_matrix(Matrix& M) {
    for (uint i = 0; i < M.size(); ++i) {
        for (uint j = 0; j < M[0].size(); ++j) {
            cin >> M[i][j];
        }
    }
}

bool pos_ok(int i, int j, const Matrix& M) {
    return i >= 0 and i < int(M.size()) and j >= 0 and j < int(M[0].size()) and M[i][j] != "*";
}

int bfs(const Matrix& M, pair<int,int>& orig, pair<int,int>& fin) {
    int f = M.size();
    int c = M[0].size();

    vector<vector<int>> dist(f,vector<int>(c,inf));
    dist[orig.first][orig.second] = 0;

    queue<pair<int,int>> Q;
    Q.push(orig);

    while (not Q.empty()) {
        // int posi = Q.front().first;
        // int posj = Q.front().second;
        pair<int,int> P = Q.front();
        Q.pop();

        if (P == fin) {
            return dist[P.first][P.second];
        }
        for (auto& d:dirs) {
            int nposi = P.first+d.first;
            int nposj = P.second+d.second;
            if (pos_ok(nposi,nposj,M) and dist[nposi][nposj] == inf) {
                dist[nposi][nposj] = dist[P.first][P.second] + 1;
                Q.push({nposi,nposj});
            }
        }
    }
    return -1;
}

pair<int,int> positions(const Matrix& M, string& s) {
    for (uint i = 0; i < M.size(); ++i) {
        for (uint j = 0; j < M[0].size(); ++j) {
            if (M[i][j] == s) return {i,j};
        }
    }
    return {-1,-1};
}

int main() {
   int f,c;
   while (cin >> f >> c) {
       Matrix M(f, VS(c));
       read_matrix(M);

       int m; cin >> m;
       VS words(m);
       for (int i = 0; i < m; ++i) cin >> words[i];

       vector<pair<int,int>> pos(m+1);
       pair<int,int> ini = {0,0};
       pos[0] = ini;
       for (int i = 0; i < m; ++i) {
           pos[i+1] = positions(M,words[i]);
       }

       int sum;
       int tot = 0;
       bool ok = true;
       for (int i = 0; ok and i < m; ++i) {
           sum = bfs(M,pos[i],pos[i+1]);
           if (sum == -1) ok = false;
           else tot += sum;
       }
       if (ok) cout << tot+m << endl;
       else cout << "impossible" << endl;
   }
}


// bool pos_ok(int i, int j, const Matrix& M) {
//     return i >= 0 and i < int(M.size()) and j >= 0 and j < int(M[0].size());
// }

// void bfs(const Matrix& M, Vpair& words) {
//     int f = M.size();
//     int c = M[0].size();

//     vector<vector<int>> dist(f,vector<int>(c,inf));
//     dist[0][0] = 0;

//     queue<pair<int,int>> Q;
//     Q.push({0,0});

//     while (not Q.empty()) {
//         int posi = Q.front().first;
//         int posj = Q.front().second;
//         Q.pop();

//         for (int k = 0; k < int(words.size()); ++k) {
//             if (M[posi][posj] == words[k].second) {
//                 words[k].first = {posi,posj};
//             }
//         }

//         for (const auto& d:dirs) {
//             int nposi = posi+d.first;
//             int nposj = posj+d.second;
//             if (pos_ok(nposi,nposj,M) and M[nposi][nposj] != "*" and dist[nposi][nposj] == inf) {
//                 dist[nposi][nposj] = dist[posi][posj] + 1;

//                 Q.push({nposi,nposj});
//             }
//         }
//     }
// }

// int main() {
//    int f,c;
//    while (cin >> f >> c) {
//        Matrix M(f, VS(c));
//        read_matrix(M);

//        int m; cin >> m;
//        Vpair words(m);
//        for (int i = 0; i < m; ++i) {
//            string str; cin >> str;
//            words[i] = {{0,0},str};
//        }
//        bfs(M,words); // words retorna la distancia (en el .first del pair) de cada palabra q buscamos

//        //CHANGE ALG
//        // int next = words[0].first;
//        // int ant = 0;
//        // int sum = 0;
//        // for (int i = 0; i < m; ++i) {
//        //     sum += abs(next-ant)+1;
//        //     ant = next;
//        //     next = words[i+1].first;
//        // }
//        // cout << sum << endl;

//        int sum = 0;
//        pair<int,int> next = words[0].first;
//        pair<int,int> ant = {0,0};
//        for (int k = 0; k < m; ++k) {

//            sum += (abs(next.first-ant.first))+(abs(next.second-ant.second)+1);
//            ant = next;
//            next = words[k+1].first;
//        }

//        if (sum > m) cout << sum << endl;
//        else cout << "impossible" << endl;
//    }
// }
