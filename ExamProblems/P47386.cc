#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,string> gossip;
    string what;
    while (cin >> what) {
        if (what == "info") {
            cout << "COUPLES:" << endl;
            for (auto it = gossip.begin(); it != gossip.end(); ++it) {
                if (it->second != "" and it->first < it->second) cout << it->first << ' ' << it->second << endl;
            }
            cout << "ALONE:" << endl;
            for (auto it = gossip.begin(); it != gossip.end(); ++it) {
                if (it->second == "") cout << it->first << endl;
            }
            cout << "----------" << endl;
        }
        // affair:
        else {
            string s1,s2; cin >> s1 >> s2;
            if (gossip[s1] != "") gossip[gossip[s1]] = "";
            if (gossip[s2] != "") gossip[gossip[s2]] = "";
            gossip[s1] = s2;
            gossip[s2] = s1;
        }
    }
}
