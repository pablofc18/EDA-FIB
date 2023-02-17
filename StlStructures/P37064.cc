#include <iostream>
#include <set>
using namespace std;

int main() {
	string s; 
	set<string> words;
	auto med = words.end();
	while (cin >> s and s != "END") {
		auto it = words.insert(s).first;
		if (med == words.end()) med = it;
		else if (words.size()%2 == 0 and s < *med) --med;
		else if (words.size()%2 != 0 and s > *med) ++med;
		cout << *med << endl;
	}
}
