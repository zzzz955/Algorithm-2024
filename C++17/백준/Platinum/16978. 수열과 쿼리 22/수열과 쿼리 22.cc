#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct updates {
	int index, value;
};

vector<long long> tree;
queue<updates> uq;
queue<tuple<int, int, int, int>> qq;
int n, m;
long long ans[1000001] = { 0 };

void build(vector<int>& lst, int node, int start, int end) {
	if (start == end) tree[node] = lst[start];
	else {
		int mid = (start + end) / 2;
		build(lst, node * 2, start, mid);
		build(lst, node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) tree[node] = val;
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) update(node * 2, start, mid, idx, val);
		else update(node * 2 + 1, mid + 1, end, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

long long query(int node, int start, int end, int L, int R) {
	if (R < start || end < L) return 0;
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	long long left = query(node * 2, start, mid, L, R);
	long long right = query(node * 2 + 1, mid + 1, end, L, R);
	return left + right;
}

void solution() {
	int uds = 0;
	while (!uq.empty() || !qq.empty()) {
		while (!qq.empty()) {
			tuple<int, int, int, int> qr = qq.front();
			int uid = get<0>(qr), start = get<1>(qr), end = get<2>(qr), qindex = get<3>(qr);
			if (uid != uds) break;
			qq.pop();
			ans[qindex] = query(1, 0, n - 1, start - 1, end - 1);
		}
		if (!uq.empty()) {
			updates ud = uq.front(); uq.pop();
			update(1, 0, n - 1, ud.index - 1, ud.value);
			uds++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int> lst(n);
	tree.resize(4 * n);
	for (int i = 0; i < n; i++) cin >> lst[i];
	build(lst, 1, 0, n - 1);

	cin >> m;
	int qrs = 0;
	vector<tuple<int, int, int, int>> temps;
	while (m--) {
		int order;
		cin >> order;
		if (order == 1) {
			int idx, val;
			cin >> idx >> val;
			uq.push({ idx, val });
		}
		else {
			int uid, start, end;
			cin >> uid >> start >> end;
			temps.push_back({ uid, start, end, qrs++ });
		}
	}
	sort(temps.begin(), temps.end(), [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {return get<0>(a) < get<0>(b); });
	for (int i = 0; i < qrs; i++) qq.push(temps[i]);
	solution();
	for (int i = 0; i < qrs; i++) {
		cout << ans[i] << "\n";
	}
}