#include<iostream>
#include<algorithm>
using namespace std;

int n;
const int MAX_N = 100000;
int nodes[MAX_N];
int tree[MAX_N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = s;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = nodes[tree[node * 2]] <= nodes[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1];
	}
}

int getIndex(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return -1;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = getIndex(node * 2, s, mid, L, R);
	int right = getIndex(node * 2 + 1, mid + 1, e, L, R);

	if (left == -1) return right;
	if (right == -1) return left;
	return nodes[left] <= nodes[right] ? left : right;
}

int query(int s, int e) {
	if (s > e) return 0;
	int min_index = getIndex(1, 0, n - 1, s, e);
	int all = nodes[min_index] * (e - s + 1);
	int left = query(s, min_index - 1);
	int right = query(min_index + 1, e);
	return max({ all, left, right });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];
	build(1, 0, n - 1);
	cout << query(0, n - 1);
}