#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = a; i <= b; i++) {
			string s = to_string(i);
			cnt += count(s.begin(), s.end(), '0');
		}
		cout << cnt << "\n";
	}
}