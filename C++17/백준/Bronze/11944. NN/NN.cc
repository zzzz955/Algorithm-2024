#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string ans = "";
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ans += to_string(n);
	}
	int length = to_string(n).size();
	int out_range = min(length * n, m);
	cout << ans.substr(0, out_range);
}