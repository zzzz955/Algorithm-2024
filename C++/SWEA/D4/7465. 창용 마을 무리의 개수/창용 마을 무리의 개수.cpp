#include<iostream>

using namespace std;

int nodes[101];
int tc, n, m, ans;

void init() {
	ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) nodes[i] = i;
}

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	nodes[B] = A;
}

void query() {
	while (m--) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		Find(i);
		if (nodes[i] == i) ans++;
	}
}

int main() {
	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		init();
		query();
		solution();
		cout << "#" << c << " " << ans << "\n";
	}
}