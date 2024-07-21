#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s1, s2;
	int tc = 0;
	while (++tc) {
		cin >> s1 >> s2;
		if (s1 == "END" && s2 == "END") break;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2) cout << "Case " << tc << ": same\n";
		else cout << "Case " << tc << ": different\n";
	}
}