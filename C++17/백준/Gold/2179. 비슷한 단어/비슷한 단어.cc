#include<iostream>
using namespace std;

int n, max_len, a1, a2;
string str[20000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int len = min(str[i].size(), str[j].size());
			if (len < max_len) continue;
			int cnt = 0;
			for (int k = 0; k < len; k++) {
				if (str[i][k] != str[j][k]) break;
				cnt++;
			}
			if (max_len < cnt) {
				max_len = cnt;
				a1 = i;
				a2 = j;
			}
		}
	}
	cout << str[a1] << "\n" << str[a2];
}