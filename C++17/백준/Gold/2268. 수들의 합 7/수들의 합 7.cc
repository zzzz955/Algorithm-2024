#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<long long> tree;

void build(vector<int>& nodes, int node, int start, int end) {
	if (start == end) {
		tree[node] = nodes[start];
	}
	else {
		int mid = (start + end) / 2;
		build(nodes, 2 * node, start, mid);
		build(nodes, 2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void update(int node, int start, int end, int idx, int value) {
	if (start == end) {
		tree[node] = value;
	}
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) {
			update(node * 2, start, mid, idx, value);
		}
		else {
			update(node * 2 + 1, mid + 1, end, idx, value);
		}
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return 0;
	} 
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	long long left_sum = query(node * 2, start, mid, left, right);
	long long right_sum = query(node * 2 + 1, mid + 1, end, left, right);
	return left_sum + right_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> nodes(n, 0);
	tree.resize(4 * n);
	build(nodes, 1, 0, n - 1);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c) swap(b, c);
			cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
		else {
			update(1, 0, n - 1, b - 1, c);
		}
	}
}