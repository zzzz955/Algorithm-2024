#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), [](char c) {return tolower(c); });
		vector<int> lst(127, 0);
		int length = s.size();
		while (length--) {
			lst[s[length]] = 1;
		}
		int cnt = 0;
		string missing = "";
		for (int i = 97; i < 123; i++) {
			if (lst[i]) cnt++;
			else missing += (char)i;
		}
		if (cnt == 26) cout << "pangram\n";
		else cout << "missing " << missing << "\n";
	}
}