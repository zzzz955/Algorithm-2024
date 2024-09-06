#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int n, k;
int backs[300001];
priority_queue<int> pq;

struct JEM {
	int w, v;
	bool operator<(const JEM& other) const {
		return w < other.w;
	}
};

JEM jems[300001];

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v; cin >> w >> v;
		jems[i] = { w, v };
	}
	for (int i = 0; i < k; i++) cin >> backs[i];
}

void solution() {
	sort(jems, jems + n);
	sort(backs, backs + k);
	long long ans = 0;
	int index = 0;
	for (int i = 0; i < k; i++) {
		while (index < n && jems[index].w <= backs[i]) pq.push(jems[index++].v);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
}