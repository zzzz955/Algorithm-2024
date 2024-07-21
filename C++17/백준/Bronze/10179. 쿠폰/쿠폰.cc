#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double a;
		cin >> a;
		printf("$%.2f\n", a * 0.8);
	}
}