#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct roca {
  double x,y,r;
};

double dist(roca a, roca b) {
  double res = sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2))-a.r-b.r;
  return res;
}

int bfs(const vector<roca>& roques, double d) {
  int n = int(roques.size());

  vector<bool> visitat(n,false);
  vector<int> salts(n,0);

  queue<int> Q;
  Q.push(0);
  visitat[0] = true;

  while (not Q.empty()) {
    int act = Q.front();
    Q.pop();
    // end of rocks
    if (act == n-1) return salts[act];

    else {
      for (int i = 0; i < n; ++i) {
        if (i!=act and not visitat[i] and d >= dist(roques[i],roques[act])) {
          salts[i] = salts[act] + 1;
          Q.push(i);
          visitat[i] = true;
        }
      }
    }
  }
  return -1;
}

int main() {
  int n;
  double d;
  while (cin >> n >> d) {
    vector<roca> roques(n);

    for (int i = 0; i < n; ++i)
      cin >> roques[i].x >> roques[i].y >> roques[i].r;

    int res = bfs(roques, d);
    if (res < 0) cout << "Xof!" << endl;
    else cout << res << endl;

  }

}
