#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string b;
		cin >> b;
		string c = b;
		reverse(c.begin(), c.end());
		string str = to_string(stoi(b) + stoi(c));
		string re_str = str;
		reverse(re_str.begin(), re_str.end());
		if (str == re_str) cout << "YES\n";
		else cout << "NO\n";
	}
}
