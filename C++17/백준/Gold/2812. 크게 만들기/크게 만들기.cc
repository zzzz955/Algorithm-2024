#include<iostream>
#include<vector>

using namespace std;
string lst;
int n, k, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> lst;
	vector<char> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.back() < lst[i] && cnt < k) {
			cnt++;
			s.pop_back();
		}
		s.push_back(lst[i]);
	}
	for (int i = 0; i < n - k; i++) cout << s[i];
}