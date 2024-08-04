#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<long long> tree;

void build(vector<long long>& nodes, int node, int start, int end) {
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

void update(int node, int start, int end, int indx, long long value) {
    if (start == end) {
        tree[node] = value;
    }
    else {
        int mid = (start + end) / 2;
        if (start <= indx && indx <= mid) {
            update(2 * node, start, mid, indx, value);
        }
        else {
            update(2 * node + 1, mid + 1, end, indx, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
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
    long long left_min = query(2 * node, start, mid, left, right);
    long long right_min = query(2 * node + 1, mid + 1, end, left, right);
    return left_min + right_min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    vector<long long> nodes;
    tree.resize(4 * n);
    
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        nodes.push_back(temp);
    }
    build(nodes, 1, 0, n - 1);

    int go = m + k;
    while (go--) {
        long long order, b, c;
        cin >> order >> b >> c;
        if (order == 2) {
            cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
        else {
            update(1, 0, n - 1, b - 1, c);
        }
    }
}
