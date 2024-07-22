#include <iostream>

using namespace std;

long long lcm(int a, int b) {
	int gcd = min(a, b);
	while (a % gcd || b % gcd) {
		gcd--;
	}
	return (long long)max(a, b) * min(a / gcd, b / gcd);
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		long long ans = lcm(a, b);
		cout << ans << "\n";
	}
}