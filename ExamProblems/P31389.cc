#include <iostream>
#include <vector>
using namespace std;

void write(int f, int c, const vector<int>& rk) {
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << (rk[i] == j ? 'R' : '.');
		}
		cout << endl;
	}
	cout << endl;
}

void rooks(int i, int f, int c, vector<int>& rk, vector<bool> seen) {
	if (i == f) write(f,c,rk);
	else {
		for (int k = 0; k < c; ++k) {
			if (not seen[k]) {
				seen[k] = true;
				rk[i] = k;
				rooks(i+1,f,c,rk,seen);
				seen[k] = false;
			}
		}
	}
}

void rooks(int f, int c) {
	vector<int> rk(c);
	vector<bool> seen(c,false);
	rooks(0,f,c,rk,seen);
}

int main() {
	int f,c;
	cin >> f >> c;
	rooks(f,c);
}
