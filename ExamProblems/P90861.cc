#include <queue>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void read_queues(vector<queue<string>>& q, int n) {
    for (int i = 0; i < n; ++i) {
        string line ;
        getline(cin,line);
        istringstream in(line);
        string name;
        while (in >> name) {
            q[i].push(name);
        }
    }
}

void leavings(vector<queue<string>>& myq) {
    cout << "DEPARTS" << endl;
    cout << string(7,'-') << endl;

    string what;
    while (cin >> what) {
        if (what == "LEAVES") {
            int idx; cin >> idx;
            --idx;
            if (idx >= 0 and idx < int(myq.size())) {
                if (not myq[idx].empty()) {
                    cout << myq[idx].front() << endl;
                    myq[idx].pop();
                }
            }
        }
        // what == "ENTERS"
        else {
            string who; cin >> who;
            int idx; cin >> idx;
            --idx;
            if (idx >= 0 and idx < int(myq.size())) {
                myq[idx].push(who);
            }

            ///////////7
            // queue<string> q = myq[idx];
            // while (not q.empty()) {
            //     cout << q.front() << "*";
            //     q.pop();
            // }
            // cout << endl;
            ///////////
        }
    }
}

void print_res(vector<queue<string>>& q) {
    cout << endl << "FINAL CONTENTS" << endl;
    cout << "--------------" << endl;
    for (uint i = 0; i < q.size(); ++i) {
        cout << "queue " << i+1 << ":";
        while (not q[i].empty()) {
            cout << ' ' << q[i].front();
            q[i].pop();
        }
        cout << endl;
    }
}

int main() {
   int n; cin >> n;
   vector<queue<string>> myqueues(n);
   string line; getline(cin,line); // read empty line (after the number n)
   read_queues(myqueues,n);
   leavings(myqueues);
   print_res(myqueues);
}
