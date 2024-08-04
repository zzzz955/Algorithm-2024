#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tree;

void build(vector<int>& nodes, int node, int start, int end) {
    if (start == end) {
        tree[node] = nodes[start];
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
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 1000000001;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_min = query(2 * node, start, mid, left, right);
    int right_min = query(2 * node + 1, mid + 1, end, left, right);
    return min(left_min, right_min);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> nodes;
    tree.resize(4 * n);
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nodes.push_back(temp);
    }
    build(nodes, 1, 0, n - 1);

    while (m--) {
        int b, c;
        cin >> b >> c;
        cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
}
