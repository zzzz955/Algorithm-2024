#include<iostream>
#include<string>
#include<vector>

using namespace std;
string str;
int n, ans;

void getLPS(string str) {
	int cur = 0, i = 1, length = str.size();
	vector<int> lps(n, 0);
	while (i < length) {
		if (str[cur] == str[i]) {
			cur++;
			lps[i] = cur;
			ans = max(ans, cur);
			i++;
		}
		else {
			if (cur != 0) cur = lps[cur - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, str);

	n = str.size();
	for (int i = 0; i < n; i++) getLPS(string(str.begin() + i, str.end()));

	cout << ans << "\n";
}