#include<iostream>
#include<queue>
using namespace std;

int n;
bool v[61][61][61];
struct SCV {
	int s1, s2, s3, t;
	bool operator < (const SCV& other) const {
		return t > other.t;
	}
};

SCV ATK(int s1, int s2, int s3, int t) {
	s1 = s1 - 9 >= 0 ? s1 - 9 : 0;
	s2 = s2 - 3 >= 0 ? s2 - 3 : 0;
	s3 = s3 - 1 >= 0 ? s3 - 1 : 0;
	return { s1, s2, s3, t + 1 };
}

int bfs(SCV& scv) {
	priority_queue<SCV> q;
	q.push(scv);
	v[scv.s1][scv.s2][scv.s3] = 1;

	while (!q.empty()) {
		SCV scv = q.top(); q.pop();
		int s1 = scv.s1, s2 = scv.s2, s3 = scv.s3, ct = scv.t;
		if (!s1 && !s2 && !s3) return ct;

		scv = ATK(s1, s2, s3, ct);
		if (!v[scv.s1][scv.s2][scv.s3]) {
			v[scv.s1][scv.s2][scv.s3] = 1;
			q.push({ scv.s1, scv.s2, scv.s3, scv.t });
		}

		scv = ATK(s1, s3, s2, ct);
		if (!v[scv.s1][scv.s3][scv.s2]) {
			v[scv.s1][scv.s3][scv.s2] = 1;
			q.push({ scv.s1, scv.s3, scv.s2, scv.t });
		}

		scv = ATK(s2, s1, s3, ct);
		if (!v[scv.s2][scv.s1][scv.s3]) {
			v[scv.s2][scv.s1][scv.s3] = 1;
			q.push({ scv.s2, scv.s1, scv.s3, scv.t });
		}

		scv = ATK(s2, s3, s1, ct);
		if (!v[scv.s2][scv.s3][scv.s1]) {
			v[scv.s2][scv.s3][scv.s1] = 1;
			q.push({ scv.s2, scv.s3, scv.s1, scv.t });
		}

		scv = ATK(s3, s1, s2, ct);
		if (!v[scv.s3][scv.s1][scv.s2]) {
			v[scv.s3][scv.s1][scv.s2] = 1;
			q.push({ scv.s3, scv.s1, scv.s2, scv.t });
		}

		scv = ATK(s3, s2, s1, ct);
		if (!v[scv.s3][scv.s2][scv.s1]) {
			v[scv.s3][scv.s2][scv.s1] = 1;
			q.push({ scv.s3, scv.s2, scv.s1, scv.t });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	SCV scv = { 0, 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		int hp; cin >> hp;
		if (i == 0) scv.s1 = hp;
		else if (i == 1) scv.s2 = hp;
		else scv.s3 = hp;
	}

	cout << bfs(scv);
}