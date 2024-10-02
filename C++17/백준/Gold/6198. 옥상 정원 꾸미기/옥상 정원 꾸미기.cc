#include<iostream>
#include<vector>

using namespace std;
long long n, ans;
int lst[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> lst[i];
	vector<int> s;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && s.back() <= lst[i]) s.pop_back();
		ans += s.size();
		s.push_back(lst[i]);
	}
	cout << ans;
}