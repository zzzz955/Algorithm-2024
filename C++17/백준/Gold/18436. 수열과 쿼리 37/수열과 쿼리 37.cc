#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> tree;

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

int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return 0;
    }
    if (L <= start && end <= R) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left = query(node * 2, start, mid, L, R);
    int right = query(node * 2 + 1, mid + 1, end, L, R);
    return left + right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2) lst[i] = -1;
        else lst[i] = 1;
    }
    tree.resize(4 * n);
    build(lst, 1, 0, n - 1);
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            if (c % 2) c = -1;
            else c = 1;
            update(1, 0, n - 1, b - 1, c);
        }
        else {
            int ans = query(1, 0, n - 1, b - 1, c - 1);
            if (a == 2) cout << (c - b + 1 + ans) / 2 << "\n";
            if (a == 3) cout << abs(ans - (c - b + 1)) / 2 << "\n";
        }
    }
}