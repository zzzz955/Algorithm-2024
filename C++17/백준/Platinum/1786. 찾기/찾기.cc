#include<iostream>
#include<string>
#include<vector>

using namespace std;
string str1, str2;
int n, m, cnt;
vector<int> lps, ans;

void getLPS(const string& str2) {
	int cur = 0, i = 1;
	lps.resize(m, 0);
	while (i < m) {
		if (str2[cur] == str2[i]) {
			cur++;
			lps[i] = cur;
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

void KMP(const string& str1, const string& str2) {
	int i = 0, j = 0;
	while (i < n) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
		}

		if (j == m) {
			cnt++;
			ans.push_back(i - j + 1);
			j = lps[j - 1];
		}
		else if (i < n && str2[j] != str1[i]) {
			if (j != 0) j = lps[j - 1];
			else i++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, str1);
	getline(cin, str2);

	n = str1.size(), m = str2.size();
	getLPS(str2);
	KMP(str1, str2);

	cout << cnt << "\n";
	for (const int& a : ans) cout << a << " ";
}