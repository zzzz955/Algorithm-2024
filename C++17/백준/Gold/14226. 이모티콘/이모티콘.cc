#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int s;
unordered_map<int, unordered_map<int, bool>> v;
struct Emo {
	int w, c, t;
	bool operator<(const Emo& other) const {
		return t > other.t;
	}
};

int bfs() {
	priority_queue<Emo> pq;
	pq.push({ 1, 0, 0 });
	v[1][0] = 1;

	while (!pq.empty()) {
		Emo emo = pq.top(); pq.pop();
		int cw = emo.w, cc = emo.c, ct = emo.t;
		if (cw == s) return ct;

		if (!v[cw][cw]) {
			v[cw][cw] = 1;
			pq.push({ cw, cw, ct + 1 });
		}
		if (cc && abs(s - cw) > abs(cw + cc - s) && !v[cw + cc][cc]) {
			v[cw + cc][cc] = 1;
			pq.push({ cw + cc, cc, ct + 1 });
		}
		if (!v[cw - 1][cc]) {
			v[cw - 1][cc] = 1;
			pq.push({ cw - 1, cc, ct + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> s;
	cout << bfs();
}