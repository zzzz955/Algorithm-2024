#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int n;
vector<int> U;
unordered_map<int, int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	U.resize(n);
	for (int i = 0; i < n; ++i) cin >> U[i];
	sort(U.begin(), U.end());

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dic[U[i] + U[j]]++;

	for (int i = n - 1; i >= 0; --i) {
		int target = U[i];
		for (int j = 0; j < i; ++j) {
			if (dic[target - U[j]]) {
				cout << target;
				return 0;
			}
		}
	}
}