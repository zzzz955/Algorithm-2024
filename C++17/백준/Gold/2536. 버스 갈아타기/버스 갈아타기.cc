#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int m, n, k, b, bx1, by1, bx2, by2, sx, sy, dx, dy;

struct Bus {
	int x1, x2, y1, y2, type;
};

int bfs(int start, vector<vector<int>>& buslist) {
	queue<pair<int, int>> q;
	vector<int> v(k + 2, 0);
	q.push({ start, 0 });
	v[start] = 1;

	while (!q.empty()) {
		int cn = q.front().first; int time = q.front().second;
		q.pop();
		for (int i : buslist[cn]) {
			if (v[i]) continue;
			if (i == k + 1) return time;
			v[i] = 1;
			q.push({ i, time + 1 });
		}
	}
}

int main() {
	cin >> m >> n >> k;
	vector<Bus> busInfo(k + 1);
	for (int i = 0; i < k; i++) {
		cin >> b >> bx1 >> by1 >> bx2 >> by2;
		if (bx1 > bx2) swap(bx1, bx2);
		if (by1 > by2) swap(by1, by2);
		int type;
		if (bx1 == bx2) type = 2;
		if (by1 == by2) type = 1;
		busInfo[b] = { bx1, bx2, by1, by2, type };
	}
	vector<vector<int>> buslist(k + 2);
	for (int i = 1; i <= k; i++) {
		Bus& b1 = busInfo[i];
		for (int j = i + 1; j <= k; j++) {
			Bus& b2 = busInfo[j];
			if (b1.type == 2 && b2.type == 2) {
				if (b1.x1 != b2.x2) continue;
				if (b1.y2 - b2.y2 >= 0 && b1.y1 > b2.y2) continue;
				if (b2.y2 - b1.y2 >= 0 && b2.y1 > b1.y2) continue;
			}
			else if (b1.type == 1 && b2.type == 1) {
				if (b1.y1 != b2.y2) continue;
				if (b1.x2 - b2.x2 >= 0 && b1.x1 > b2.x2) continue;
				if (b2.x2 - b1.x2 >= 0 && b2.x1 > b1.x2) continue;
			}
			else {
				if (b1.type == 2 && b2.type == 1) {
					if (b2.x1 > b1.x1 || b1.x1 > b2.x2) continue;
					if (b1.y1 > b2.y1 || b2.y1 > b1.y2) continue;
				}
				if (b1.type == 1 && b2.type == 2) {
					if (b1.x1 > b2.x1 || b2.x1 > b1.x2) continue;
					if (b2.y1 > b1.y1 || b1.y1 > b2.y2) continue;
				}
			}
			buslist[i].push_back(j);
			buslist[j].push_back(i);
		}
	}
	cin >> sx >> sy >> dx >> dy;
	Bus sb = { sx, sy, sx, sy };
	Bus db = { dx, dy, dx, dy };
	for (int i = 1; i <= k; i++) {
		Bus& bus = busInfo[i];
		if (bus.x1 <= sx && sx <= bus.x2 && bus.y1 <= sy && sy <= bus.y2) {
			buslist[i].push_back(0);
			buslist[0].push_back(i);
		}
		if (bus.x1 <= dx && dx <= bus.x2 && bus.y1 <= dy && dy <= bus.y2) {
			buslist[i].push_back(k + 1);
			buslist[k + 1].push_back(i);
		}
	}
	cout << bfs(0, buslist);
}