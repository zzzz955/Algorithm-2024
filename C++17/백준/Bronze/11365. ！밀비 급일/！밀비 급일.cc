#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "END") break;
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
}