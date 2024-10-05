#include<iostream>
#include<vector>

using namespace std;
int n, lst[1000001], v[1000001], ans[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		v[lst[i]]++;
	}
	vector<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && v[s.back()] <= v[lst[i]]) s.pop_back();
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.back();
		s.push_back(lst[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
}