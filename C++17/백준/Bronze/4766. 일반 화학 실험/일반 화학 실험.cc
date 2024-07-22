#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double temp;
	cin >> temp;

	while (1) {
		double d;
		cin >> d;
		if ((int)d == 999) break;
		double ans = d - temp;
		temp = d;
		printf("%.2f\n", ans);
	}
}