#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	int a = 0, ans = 1e9;
	for (int i = 0; i < n; i++) if (s[i] == 'a') a++;

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i; j < i + a; j++) {
			if (s[j % n] == 'b') cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}