#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		bool flag = false;
		if (s == "EOI") break;
		int length = s.size();
		while (length--) {
			s[length] = tolower(s[length]);
		}
		if (s.find("nemo") != s.npos) cout << "Found\n";
		else cout << "Missing\n";
	}
}