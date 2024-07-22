#include <iostream>

using namespace std;

int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "#") break;
		int cnt = 0, length = s.size();
		for (int i = 0; i < length; i++) {
			if (s[i] == '1') cnt++;
		}
		if (s[length - 1] == 'e') {
			if (cnt % 2) s[length - 1] = '1';
			else s[length - 1] = '0';
		}
		else {
			if (cnt % 2) s[length - 1] = '0';
			else s[length - 1] = '1';
		}
		cout << s << "\n";
	}
}