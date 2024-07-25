#include <iostream>
#include <string>

using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "#") break;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') sum += (i + 1) * (s[i] - 64);
		}
		cout << sum << "\n";
	}
}
