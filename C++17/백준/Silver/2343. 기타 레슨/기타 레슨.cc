#include<iostream>

using namespace std;
int n, m, gang[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int left = 0, right = 0;
	for (int i = 1; i <= n; i++) {
		cin >> gang[i];
		left = max(left, gang[i]);
		right += gang[i];
	}
	
	while (left <= right) {
		int sum = 0, cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) {
			if (sum + gang[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += gang[i];
		}
		if (sum) cnt++;
		if (cnt <= m) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
}