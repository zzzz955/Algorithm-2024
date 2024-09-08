#include<iostream>
#include<algorithm>

using namespace std;

int house[200001];
int n, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> house[i];
	sort(house, house + n);
	int left = 1, right = house[n - 1] - house[0] + 1;
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int cur = house[0];
		for (int i = 1; i < n; i++) {
			if (house[i] - cur >= mid) {
				cnt++;
				cur = house[i];
			}
		}
		if (cnt >= c) {
			result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result;
}