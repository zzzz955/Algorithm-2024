#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s, ans = "";
	string mouem = "aeiou";
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (mouem.find(s[i]) == mouem.npos) {
			ans += s[i];
		}
		else {
			ans += s[i];
			i += 2;
		}
	}
	cout << ans;
}