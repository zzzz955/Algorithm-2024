#include <iostream>

using namespace std;

int main() {
	int arr[7];
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}
	int min_odd = 100;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2) {
			min_odd = min(min_odd, arr[i]);
			sum += arr[i];
		}
	}
	if (sum) {
		cout << sum << "\n";
		cout << min_odd;
	}
	else cout << -1;
}