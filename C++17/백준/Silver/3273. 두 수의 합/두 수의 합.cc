#include<iostream>
#include<algorithm>

using namespace std;

int n, target;
int arr[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> target;
	sort(arr, arr + n);
	int cnt = 0, left = 0, right = n - 1;
	while (left < right) {
		if (arr[left] + arr[right] > target) right--;
		else if (arr[left] + arr[right] < target) left++;
		else {
			cnt++;
			left++;
			right--;
		}
	}
	cout << cnt;
}