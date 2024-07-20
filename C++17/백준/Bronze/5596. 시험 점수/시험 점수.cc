#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int max_sum = 0;
	for (int i = 0; i < 2; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		max_sum = max(max_sum, a + b + c + d);
	}
	cout << max_sum;
}