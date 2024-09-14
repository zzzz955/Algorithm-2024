#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> lst[i];
	sort(lst, lst + n);
	int left = 0, right = n - 1;
	int al, ar, ans = 2e9;
	while (left < right) {
		int sum = lst[left] + lst[right];
		if (ans > abs(sum)) {
			ans = abs(sum);
			al = lst[left], ar = lst[right];
		}
		if (sum < 0) left++;
		else if (sum > 0) right--;
		else {
			al = lst[left], ar = lst[right];
			break;
		}
	}
	cout << al << " " << ar;
}