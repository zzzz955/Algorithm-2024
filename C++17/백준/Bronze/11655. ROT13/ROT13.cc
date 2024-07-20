#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s, ans = "";
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if ((65 <= s[i] && s[i] < 78) || (97 <= s[i] && s[i] < 110)) ans += s[i] + 13;
		else if ((78 <= s[i] && s[i] < 91) || (110 <= s[i] && s[i] < 123)) ans += s[i] - 13;
		else ans += s[i];
	}
	cout << ans;
}