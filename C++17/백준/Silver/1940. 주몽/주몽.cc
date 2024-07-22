#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int twoPointer(vector<int>& lst, int n, int m) {
	int left = 0, right = n - 1, cnt = 0;
	while (left < right) {
		int temp = lst[left] + lst[right];
		if (temp == m) {
			cnt++;
			left++;
			right--;
		}
		else if (temp > m) right--;
		else left++;
	}
	return cnt;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	sort(lst.begin(), lst.end());
	int ans = twoPointer(lst, n, m);
	cout << ans;
}