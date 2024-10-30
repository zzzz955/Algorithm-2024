#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int t, n, k;
string w;
unordered_map<char, vector<int>> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		dic.clear();
		cin >> w >> k;
		n = w.size();
		
		int case1 = 1e9, case2 = 0;
		for (int i = 0; i < n; i++) dic[w[i]].push_back(i);
		for (auto d : dic) {
			int key = d.first;
			vector<int> val = d.second;
			int m = val.size();
			if (m < k) continue;
			for (int i = 0; i <= m - k; i++) {
				case1 = min(case1, val[i + k - 1] - val[i] + 1);
				case2 = max(case2, val[i + k - 1] - val[i] + 1);
			}
		}
		if (case1 == 1e9 || !case2) cout << -1 << "\n";
		else cout << case1 << " " << case2 << "\n";
	}
}