#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int n;
vector<pii> lst;
vector<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		lst.push_back({ a, b });
	}
	sort(lst.begin(), lst.end());

	vector<int> index(n);
	for (int i = 0; i < n; ++i) {
		pii cur = lst[i];
		auto it = lower_bound(lis.begin(), lis.end(), cur.second);
		index[i] = it - lis.begin();

		if (it == lis.end()) lis.push_back(cur.second);
		else *it = cur.second;
	}

	int len = lis.size() - 1;
	vector<int> result;
	for (int i = n - 1; i >= 0; --i) {
		if (index[i] == len) len--;
		else result.push_back(lst[i].first);
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i : result) cout << i << "\n";
}