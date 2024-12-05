#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int t, s, e, v[10000];
struct Cur {
	int num;
	string op;
};

string bfs() {
	queue<Cur> q;
	q.push({ s, "" });
	v[s] = 1;

	while (!q.empty()) {
		Cur cur = q.front(); q.pop();
		int num = cur.num;
		string op = cur.op;
		if (num == e) return op;

		int D, S, L, R;
		D = num * 2 % 10000;
		if (!v[D]) {
			v[D] = 1;
			q.push({ D, op + 'D' });
		}

		S = num > 0 ? num - 1 : 9999;
		if (!v[S]) {
			v[S] = 1;
			q.push({ S, op + 'S' });
		}

		L = num % 1000 * 10 + num / 1000;
		if (!v[L]) {
			v[L] = 1;
			q.push({ L, op + 'L' });
		}

		R = num % 10 * 1000 + num / 10;
		if (!v[R]) {
			v[R] = 1;
			q.push({ R, op + 'R' });
		}
	}
	return "CANT";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> s >> e;
		memset(v, 0, sizeof(v));
		cout << bfs() << "\n";
	}
}
