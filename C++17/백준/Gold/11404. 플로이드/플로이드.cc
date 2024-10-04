#include<iostream>
#include<vector>
#define ll long long

using namespace std;
const ll MAX_D = 1e11;
int n, m;
ll lst[101][101];
vector<vector<pair<ll, ll>>> path;
vector<vector<ll>> dist;

void input() {
	cin >> n >> m;
	path.resize(n + 1);
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;
		path[a].push_back({ b, c });
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (const auto& val : path[i]) {
			ll j = val.first, w = val.second;
			if (lst[i][j]) lst[i][j] = min(lst[i][j], w);
			else lst[i][j] = w;
		}
	}
	dist.resize(n + 1, vector<ll>(n + 1, MAX_D));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (lst[i][j]) dist[i][j] = lst[i][j];
		}
	}
}

void solution() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX_D || i == j) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	init();
	solution();
}