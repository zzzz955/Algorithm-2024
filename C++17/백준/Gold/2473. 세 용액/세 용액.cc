#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long

using namespace std;

int n;
int dx[] = { -1, 1 };
ll lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> lst[i];
	sort(lst, lst + n);

	int al, am, ar;
	ll ans = 3e9;
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1, right = n - 1;
		while (left < right) {
			ll sum = lst[i] + lst[left] + lst[right];
			if (ans > abs(sum)) {
				ans = abs(sum);
				al = lst[i], am = lst[left], ar = lst[right];
			}
			if (sum < 0) left++;
			else if (sum > 0) right--;
			if (sum == 0) {
				al = lst[i], am = lst[left], ar = lst[right];
				break;
			}
		}
	}
	cout << al << " " << am << " " << ar;
}