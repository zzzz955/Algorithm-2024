#include<iostream>
#include<vector>
using namespace std;

const int N = 100001;
int n, k;
int tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = 1;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int k) {
	if (s == e) {
		tree[node] = 0;
		return s;
	}
	int mid = (s + e) / 2;
	int result;
	if (k <= tree[node * 2]) result = query(node * 2, s, mid, k);
	else result = query(node * 2 + 1, mid + 1, e, k - tree[node * 2]);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	build(1, 1, n);

	vector<int> ans;
	int idx = k;
	for (int i = 0; i < n; ++i) {
		int result = query(1, 1, n, idx);
		ans.push_back(result);
		if (i < n - 1) {
			idx = (idx - 1 + k) % tree[1];
			if (idx == 0) idx = tree[1];
		}
	}

	cout << "<";
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
		if (i < n - 1) cout << ", ";
	}
	cout << ">";
}