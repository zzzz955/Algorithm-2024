#include<iostream>
#define ll long long
using namespace std;

const int N = 2000001;
const int M = 1000001;
int n, m;
int lst[M];
int g[N];
ll tree[M * 4];
ll lazy[M * 4];

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, ll val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] = val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = lst[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		for (int j = a; j <= b; ++j) g[j] = i;
		lst[i] = c;
	}

	build(1, 1, m);

	while (1) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			ll result = 0;
			int gx = g[x], gy = g[y];
			if (x <= y) result += query(1, 1, m, gx, gy);
			else {
				result += query(1, 1, m, gx, m);
				result += query(1, 1, m, 1, gy);
			}
			cout << result << "\n";
		}
		else if (op == 2) {
			int x, y; cin >> x >> y;
			ll z; cin >> z;
			int gx = g[x], gy = g[y];
			if (x <= y) update(1, 1, m, gx, gy, z);
			else {
				update(1, 1, m, gx, m, z);
				update(1, 1, m, 1, gy, z);
			}
		}
		else {
			int temp; cin >> temp >> temp;
			break;
		}
	}
}