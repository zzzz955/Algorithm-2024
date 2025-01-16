#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Child {
	int l, r;
};
bool v[100001];
int par[100001];
int n, en, ans;
vector<Child> nodes(100001);

void find_end(int node) {
	if (node == -1) return;
	find_end(nodes[node].l);
	en = node;
	find_end(nodes[node].r);
}

void dfs(int node) {
	if (nodes[node].l != -1 && !v[nodes[node].l]) {
		v[nodes[node].l] = true;
		ans++;
		dfs(nodes[node].l);
	}
	else if (nodes[node].r != -1 && !v[nodes[node].r]) {
		v[nodes[node].r] = true;
		ans++;
		dfs(nodes[node].r);
	}
	else if (node == en) return;
	else {
		ans++;
		dfs(par[node]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int a, b, c; cin >> a >> b >> c;
		nodes[a] = { b, c };
		par[b] = a;
		par[c] = a;
	}
	par[1] = 1;
	find_end(1);
	dfs(1);
	cout << ans;
}