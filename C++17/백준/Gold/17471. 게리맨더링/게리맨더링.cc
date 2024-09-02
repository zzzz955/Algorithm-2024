#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, ans;
int lst[10][10] = { 0, };
int men[10];

bool bfs(vector<int>& a) {
	int length = a.size();
	queue<int> q;
	q.push(a[0]);
	int v[10] = { 0, };
	v[a[0]] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (int i = 0; i < length; i++) {
			if (!v[a[i]] && lst[cn][a[i]]) {
				v[a[i]] = 1;
				cnt++;
				q.push(a[i]);
			}
		}
	}
	return cnt == length;
}

void dfs(int level, vector<int>& a, vector<int>& b) {
	if (level == n) {
		if (!a.empty() && !b.empty()) {
			if (bfs(a) && bfs(b)) {
				int A = 0, B = 0;
				for (int i = 0; i < a.size(); i++) A += men[a[i]];
				for (int i = 0; i < b.size(); i++) B += men[b[i]];
				ans = min(ans, abs(A - B));
			}
		}
		return;
	}

	a.push_back(level);
	dfs(level + 1, a, b);
	a.pop_back();

	b.push_back(level);
	dfs(level + 1, a, b);
	b.pop_back();
}

int main() {
	cin >> n;
	ans = 1e9;
	for (int i = 0; i < n; i++) cin >> men[i];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			b--;
			lst[i][b] = 1;
			lst[b][i] = 1;
		}
	}
	vector<int> a, b;
	dfs(0, a, b);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}