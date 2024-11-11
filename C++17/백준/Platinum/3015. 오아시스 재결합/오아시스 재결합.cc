#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

long long n, ans;
long long nodes[555555];
unordered_map<long long, long long> cnt;
vector<long long> stack;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> nodes[i];

	cnt[nodes[0]]++;
	stack.push_back(nodes[0]);
	for (int i = 1; i < n; ++i) {
		if (stack.back() == nodes[i]) {
			ans += cnt[nodes[i]];
			cnt[nodes[i]]++;
			if (stack.size() >= 2) ans++;
			continue;
		}
		else if (stack.back() < nodes[i]) {
			ans += cnt[nodes[i]];
			while (!stack.empty() && stack.back() <= nodes[i]) {
				if (stack.back() < nodes[i]) {
					ans += cnt[stack.back()];
					cnt[stack.back()] = 0;
				}
				stack.pop_back();
			}
			if (!stack.empty() && stack.back() > nodes[i]) ans++;
		}
		else ans++;
		
		cnt[nodes[i]]++;
		stack.push_back(nodes[i]);
	}
	cout << ans;
}