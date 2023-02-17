#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef pair<string,string> PrNames;
typedef pair<int,int> PrVotes;


int main() {
    int n;
    while (cin >> n) {
        map<string,string> M;
        // read proposals
        for (int i = 0; i < n; ++i) {
            string nom, proposta;
            cin >> nom >> proposta;
            M[proposta] = nom;
        }
        // read votes
        int m; cin >> m;
        map<PrNames,bool> Votes;
        for (int i = 0; i < m; i++) {
            string nom, si_no, proposta;
            cin >> nom >> si_no >> proposta;
            // create another map only for votes
            Votes[PrNames(nom,proposta)] = si_no == "SI";
        }
        // count votes
        map<string,PrVotes> votes_count;
        for (auto& p:Votes) {
            if (p.second) ++votes_count[p.first.second].first;
            else ++votes_count[p.first.second].second;
        }

        // print proposals
        for (auto& p:votes_count) {
            if (p.second.first > p.second.second) {
                cout << p.first << ", de " << M[p.first] << ", que ha guanyat " << p.second.first << "-" << p.second.second;
                cout << endl;
            }
        }

        cout << "----------" << endl;
    }
}
