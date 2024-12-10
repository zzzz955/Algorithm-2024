#include<iostream>
#include<queue>
#include<set>
using namespace std;

int A, B, C;
int v[201][201][201];
set<int> ans;
struct Status {
	int a, b, c;
};

void bfs() {
	queue<Status> q;
	q.push({ 0, 0, C });
	v[0][0][C] = 1;

	while (!q.empty()) {
		Status status = q.front(); q.pop();
		int ca = status.a, cb = status.b, cc = status.c;
		if (!ca) ans.insert(cc);

		if (ca) {
			if (cb != B) {
				int diff = min(ca, B - cb);
				if (!v[ca - diff][cb + diff][cc]) {
					v[ca - diff][cb + diff][cc] = 1;
					q.push({ ca - diff, cb + diff, cc });
				}
			}
			if (cc != C) {
				int diff = min(ca, C - cc);
				if (!v[ca - diff][cb][cc + diff]) {
					v[ca - diff][cb][cc + diff] = 1;
					q.push({ ca - diff, cb, cc + diff });
				}
			}
		}

		if (cb) {
			if (ca != A) {
				int diff = min(cb, A - ca);
				if (!v[ca + diff][cb - diff][cc]) {
					v[ca + diff][cb - diff][cc] = 1;
					q.push({ ca + diff, cb - diff, cc });
				}
			}
			if (cc != C) {
				int diff = min(cb, C - cc);
				if (!v[ca][cb - diff][cc + diff]) {
					v[ca][cb - diff][cc + diff] = 1;
					q.push({ ca, cb - diff, cc + diff });
				}
			}
		}

		if (cc) {
			if (ca != A) {
				int diff = min(cc, A - ca);
				if (!v[ca + diff][cb][cc - diff]) {
					v[ca + diff][cb][cc - diff] = 1;
					q.push({ ca + diff, cb, cc - diff });
				}
			}
			if (cb != B) {
				int diff = min(cc, B - cb);
				if (!v[ca][cb + diff][cc - diff]) {
					v[ca][cb + diff][cc - diff] = 1;
					q.push({ ca, cb + diff, cc - diff });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;
	bfs();
	for (int i : ans) cout << i << " ";
}
