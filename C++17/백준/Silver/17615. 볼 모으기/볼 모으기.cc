#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, cnt, ans = 2e9;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	vector<int> ans;
	cnt = 0;
	for (int i = n - 1; i > 0; i--) {
		if (s[i] == 'B') {
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == 'R') cnt++;
			}
			break;
		}
	}
	ans.push_back(cnt);

	cnt = 0;
	for (int i = n - 1; i > 0; i--) {
		if (s[i] == 'R') {
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == 'B')cnt++;
			}
			break;
		}
	}
	ans.push_back(cnt);

	cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'B') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'R') cnt++;
			}
			break;
		}
	}
	ans.push_back(cnt);

	cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'R') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'B') cnt++;
			}
			break;
		}
	}
	ans.push_back(cnt);


	cout << *min_element(ans.begin(), ans.end());
}