#include<iostream>
#include<queue>

using namespace std;

int n, x, y;

struct Line {
	int x, y;
	bool operator<(const Line& other) const {
		if (x == other.x) return y < other.y;
		return x > other.x;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<Line> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pq.push({ x, y });
	}

	int l = -1000000000;
	int len = 0;
	for (int i = 0; i < n; i++) {
		Line line = pq.top(); pq.pop();
		if (l < line.x) l = line.x;

		if (l < line.y) {
			len += line.y - l;
			l = line.y;
		}
	}
	cout << len;
}