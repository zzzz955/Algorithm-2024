#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n, k, ans;
unordered_set<int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<int> lst(k);
	for (int i = 0; i < k; ++i) cin >> lst[i];

	for (int i = 0; i < k; ++i) {
		int id = lst[i];
		if (dic.size() < n || dic.count(id)) dic.insert(id);
		else {
			int Del = -1, Midx = -1;
			for (int num : dic) {
				auto it = find(lst.begin() + i, lst.end(), num);
				if (it == lst.end()) {
					Del = num;
					break;
				}
				int idx = it - lst.begin();
				if (idx > Midx) {
					Del = num;
					Midx = idx;
				}
			}
			ans++;
			dic.erase(Del);
			dic.insert(id);
		}
	}
	cout << ans;
}