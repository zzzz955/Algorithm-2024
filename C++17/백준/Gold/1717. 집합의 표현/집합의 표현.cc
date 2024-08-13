#include<iostream>

using namespace std;

int n, m;
int nodes[1000001];

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
    for (int i = 1; i <= n; i++) {
        nodes[i] = i;
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a) Union(b, c);
        else {
            if (Find(b) == Find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}