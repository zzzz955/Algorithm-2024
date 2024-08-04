#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> tree;

void build(vector<int>& nodes, int node, int start, int end) {
    if (start == end) {
        tree[node] = { nodes[start], start };
    }
    else {
        int mid = (start + end) / 2;
        build(nodes, 2 * node, start, mid);
        build(nodes, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int indx, int value) {
    if (start == end) {
        tree[node] = { value, start };
    }
    else {
        int mid = (start + end) / 2;
        if (start <= indx && indx <= mid) {
            update(2 * node, start, mid, indx, value);
        }
        else {
            update(2 * node + 1, mid + 1, end, indx, value);
        }
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return INT_MAX;
    }
    if (left <= start && end <= right) {
        return tree[node].second;
    }
    int mid = (start + end) / 2;
    int left_min = query(2 * node, start, mid, left, right);
    int right_min = query(2 * node + 1, mid + 1, end, left, right);
    return min(left_min, right_min);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> nodes;
    tree.resize(4 * n);
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nodes.push_back(temp);
    }
    build(nodes, 1, 0, n - 1);

    cin >> m;
    while (m--) {
        int order;
        cin >> order;
        if (order == 2) {
            cout << query(1, 0, n - 1, 0, n - 1) + 1 << "\n";
        }
        else {
            int id1, id2;
            cin >> id1 >> id2;
            update(1, 0, n - 1, id1 - 1, id2);
        }
    }
}
