#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int sum = 1;
	for (i = 0; i < n; i++) {
		cin >> j;
		sum += j - 1;
	}
	cout << sum;
}