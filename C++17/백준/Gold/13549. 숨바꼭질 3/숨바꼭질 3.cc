#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, int time, int k) {
	queue<pair<int, int>> q;
	vector<bool> v(100001, false);
	q.push({ start, time });
	v[start] = true;
	while (!q.empty()) {
		int x = q.front().first;
		time = q.front().second;
		q.pop();
		if (x == k) return time;
		int nx1 = x * 2, nx2 = x - 1, nx3 = x + 1;
		if (abs(k - nx1) < abs(k - nx2) && 0 <= nx1 && nx1 < 100001 && !v[nx1]) {
			v[nx1] = true;
			q.push({ nx1, time });
		}
		if (0 <= nx2 && nx2 < 100001 && !v[nx2]) {
			v[nx2] = true;
			q.push({ nx2, time + 1});
		}
		if (abs(k - nx3) < abs(k - nx2) && 0 <= nx3 && nx3 < 100001 && !v[nx3]) {
			v[nx3] = true;
			q.push({ nx3, time + 1 });
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, 0, k);
}