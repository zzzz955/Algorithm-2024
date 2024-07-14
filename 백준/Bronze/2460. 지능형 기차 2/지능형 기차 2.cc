#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b, i;
	int max_val = 0, val = 0;
	for (i = 0; i < 10; i++) {
		cin >> a >> b;
		val += b - a;
		max_val = max(max_val, val);
	}
	cout << max_val;
}