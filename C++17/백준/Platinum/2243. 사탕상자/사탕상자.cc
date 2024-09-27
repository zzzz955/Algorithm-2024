#include<iostream>

using namespace std;

int tree[4000004];

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx) return;
	if (start == idx && end == idx) {
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int idx) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (tree[node * 2] >= idx) return query(node * 2, start, mid, idx);
	return query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while (n--) {
		int order; cin >> order;
		if (order == 2) {
			int index, val; cin >> index >> val;
			update(1, 1, 1000000, index, val);
		}
		else {
			int index; cin >> index;
			int result = query(1, 1, 1000000, index);
			cout << result << "\n";
			update(1, 1, 1000000, result, -1);
		}
	}
	
}