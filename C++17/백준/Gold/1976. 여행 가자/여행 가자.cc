#include<iostream>

using namespace std;

int n, m;
int nodes[201];

int Find(int a) {
    if (nodes[a] == a) return a;
    return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA == rootB) return;
    nodes[rootB] = rootA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) nodes[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int path; cin >> path;
            if (j >= i && path == 1) Union(i, j);
        }
    }

    int privious; cin >> privious;
    int flag = 1;
    for (int i = 0; i < m - 1; i++) {
        int node; cin >> node;
        if (Find(node) != Find(privious)) {
            flag = 0;
            break;
        }
        privious = node;
    }
    if (flag) cout << "YES";
    else cout << "NO";
}