#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b, ans = "";
	cin >> a >> b;
	int a_len = a.size(), b_len = b.size();
	for (int i = 0; i < abs(a_len - b_len); i++) {
		if (a_len > b_len) ans += a[i];
		else ans += b[i];
	}
	for (int i = 0; i < min(a_len, b_len); i++) {
		if (a_len > b_len) ans += to_string((a[i + abs(a_len - b_len)] - 48) + (b[i] - 48));
		else ans += to_string((a[i] - 48) + (b[i + abs(a_len - b_len)] - 48));
	}
	cout << ans;
}