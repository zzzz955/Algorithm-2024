#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/
	int t;
	cin >> t;
	double lst[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
	while (t--) {
		int a, b, c, d, e;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		double ans = lst[0] * a + lst[1] * b + lst[2] * c + lst[3] * d + lst[4] * e;
		printf("$%.2f\n", ans);
	}
}