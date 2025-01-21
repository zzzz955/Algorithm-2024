#include<iostream>
#include<cmath>
using namespace std;

int main() {
	long long n; cin >> n;
	
	long long ans = n;
	long long p = 2;
	while (p <= sqrt(n)) {
		if (n % p == 0) {
			while (n % p == 0) n /= p;
			ans = ans / p * (p - 1);
		}
		p++;
	}
	if (n > 1) ans = ans / n * (n - 1);
	cout << ans;
}