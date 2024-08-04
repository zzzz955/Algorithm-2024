#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tree_min;
vector<int> tree_max;

void build_min(vector<int>& nodes, int node, int start, int end) {
    if (start == end) {
        tree_min[node] = nodes[start];
    }
    else {
        int mid = (start + end) / 2;
        build_min(nodes, 2 * node, start, mid);
        build_min(nodes, 2 * node + 1, mid + 1, end);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
    }
}

int query_min(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 1000000001;
    }
    if (left <= start && end <= right) {
        return tree_min[node];
    }
    int mid = (start + end) / 2;
    int left_min = query_min(2 * node, start, mid, left, right);
    int right_min = query_min(2 * node + 1, mid + 1, end, left, right);
    return min(left_min, right_min);
}

void build_max(vector<int>& nodes, int node, int start, int end) {
    if (start == end) {
        tree_max[node] = nodes[start];
    }
    else {
        int mid = (start + end) / 2;
        build_max(nodes, 2 * node, start, mid);
        build_max(nodes, 2 * node + 1, mid + 1, end);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }
}

int query_max(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree_max[node];
    }
    int mid = (start + end) / 2;
    int left_max = query_max(2 * node, start, mid, left, right);
    int right_max = query_max(2 * node + 1, mid + 1, end, left, right);
    return max(left_max, right_max);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> nodes;
    tree_min.resize(4 * n);
    tree_max.resize(4 * n);
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nodes.push_back(temp);
    }
    build_min(nodes, 1, 0, n - 1);
    build_max(nodes, 1, 0, n - 1);

    while (m--) {
        int b, c;
        cin >> b >> c;
        cout << query_min(1, 0, n - 1, b - 1, c - 1) << " " << query_max(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
}
