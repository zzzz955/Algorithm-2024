#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<long long> fibo(68, 1);
	fibo[1] = 1, fibo[2] = 2, fibo[3] = 4;
	for (int i = 4; i < 68; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	}
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		cout << fibo[c] << "\n";
	}
}
