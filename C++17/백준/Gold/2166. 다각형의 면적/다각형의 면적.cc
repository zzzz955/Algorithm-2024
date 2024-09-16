#include<iostream>

using namespace std;

int n;
double ans = 0;

struct Pos {
	double x, y;
};

Pos poses[10000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		poses[i] = { x, y };
	}

	for (int i = 0; i < n - 1; i++) {
		Pos pos1 = poses[i];
		Pos pos2 = poses[i + 1];
		double x1 = pos1.x, y1 = pos1.y, x2 = pos2.x, y2 = pos2.y;
		ans += x1 * y2 - y1 * x2;
	}
	ans += poses[n - 1].x * poses[0].y - poses[n - 1].y * poses[0].x;
	ans /= 2;
	printf("%.1f", abs(ans));
}