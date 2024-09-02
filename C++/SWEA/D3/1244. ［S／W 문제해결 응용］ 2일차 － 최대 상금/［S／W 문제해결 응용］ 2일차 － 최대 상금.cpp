#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int tc, k, ans, length;
string s;

void bt(int level, int cnt) {
	if (cnt == k) {
		ans = max(ans, stoi(s));
		return;
	}
	int flag = 1;
	for (int i = level; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (s[i] < s[j]) {
				flag = 0;
				swap(s[i], s[j]);
				bt(level + 1, cnt + 1);
				swap(s[j], s[i]);
			}
		}
	}
	if (flag) {
		if ((k - cnt) % 2) {
			int flag = 0;
			for (char c = '0'; c <= '9'; c++) {
				if (count(s.begin(), s.end(), c) > 1) {
					flag = 1;
					break;
				}
			}
			if (flag) ans = max(ans, stoi(s));
			else {
				string temp = s;
				swap(temp[length - 2], temp[length - 1]);
				ans = max(ans, stoi(temp));
			}
		}
		else {
			ans = max(ans, stoi(s));
		}
		return;
	}
}

int main() {
	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		cin >> s >> k;
		ans = 0, length = s.size();
		bt(0, 0);
		cout << "#" << c << " " << ans << "\n";
	}
}