#include<iostream>
#include<deque>
#include<cstring>
#include<cmath>

using namespace std;

int tc, k, ans;
deque<int> mag[5];
int v[5];

void init() {
	ans = 0;
	for (int i = 0; i < 5; i++) mag[i].clear();
}

void input() {
	cin >> k;
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			int a; cin >> a;
			mag[i].push_back({ a });
		}
	}
}

void bt(int index, int dir, int turn) {
	if (1 < index && !v[index - 1]) {
		v[index - 1] = 1;
		int ndir = dir, nturn = turn;
		if (mag[index - 1][2] != mag[index][6]) {
			ndir *= -1;
		}
		else {
			nturn = 0;
		}
		bt(index - 1, ndir, min(turn, nturn));
	}
	if (index < 4 && !v[index + 1]) {
		v[index + 1] = 1;
		int ndir = dir, nturn = turn;
		if (mag[index][2] != mag[index + 1][6]) {
			ndir *= -1;
		}
		else {
			nturn = 0;
		}
		bt(index + 1, ndir, min(turn, nturn));
	}
	if (turn && dir == 1) {
		mag[index].push_front(mag[index].back());
		mag[index].pop_back();
	}
	else if (turn && dir == -1) {
		mag[index].push_back(mag[index].front());
		mag[index].pop_front();
	}
	
	
}

void solution() {
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		memset(v, 0, sizeof(v));
		v[a] = 1;
		bt(a, b, 1);
	}
	for (int i = 1; i <= 4; i++) {
		ans += mag[i].front() * pow(2, i - 1);
	}
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		solution();
		cout << "#" << t << " " << ans << "\n";
	}
}