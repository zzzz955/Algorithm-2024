#include<iostream>

using namespace std;

const int MAX_N = 200001;
const int LOG = 20;

int m, q, n, x;
int par[MAX_N][LOG];

void preprocess() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= m; i++) {
			if (par[i][j - 1] != -1) par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

void lca() {
	for (int i = 0; i < LOG; i++) {
		if ((n >> i) & 1) x = par[x][i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	for (int i = 1; i <= m; i++) cin >> par[i][0];

	preprocess();

	cin >> q;
	while (q--) {
		cin >> n >> x;
		lca();
		cout << x << "\n";
	}
}
