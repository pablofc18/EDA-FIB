#include <iostream>
#include <map>
using namespace std;

int main() {
   int n;
   while (cin >> n) {
       map<string,int> games_have;
       int count_games_poss = n;
       for (int i = 0; i < n; ++i) {
           string gm; cin >> gm;
           // map de los juegos que tiene + cuantos
           if (i == 0 or games_have.find(gm) == games_have.end()) {
               games_have[gm] = 1;
           }
           else if (games_have.find(gm) != games_have.end()) ++games_have[gm];
       }

       // new games
       int j; cin >> j;
       for (int i = 0; i < j; ++i) {
           string gm; cin >> gm;
           // si existeix
           if (games_have.find(gm) != games_have.end()) {
               // la resta >= tipus
               if (count_games_poss - games_have[gm] >= games_have[gm]+1) {
                   ++count_games_poss;
                   ++games_have[gm];
               }
           }
           else {
               games_have[gm] = 1;
               ++count_games_poss;
           }
       }

       // print games
       for (auto it:games_have) {
           cout << it.first << ' ' << it.second << endl;
       }
       cout << string(20,'-') << endl;
   }
}
