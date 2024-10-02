#include<iostream>
#include<queue>

using namespace std;
int n, ans;

struct Ing {
	int s, t;
	bool operator<(const Ing& other) const {
		if (t > other.t) return true;
		if (t < other.t) return false;
		if (s > other.s) return true;
		if (s < other.s) return false;
		return false;
	}
};

struct Stay {
	int s, t;
	bool operator<(const Stay& other) const {
		if (s > other.s) return true;
		if (s < other.s) return false;
		if (t > other.t) return true;
		if (t < other.t) return false;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<Ing> pq1;
	priority_queue<Stay> pq2;
	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		pq2.push({ s, t });
	}
	while (!pq2.empty()) {
		Stay stay = pq2.top(); pq2.pop();
		int s = stay.s, t = stay.t;
		while (!pq1.empty() && pq1.top().t <= s) pq1.pop();
		pq1.push({ s, t });
		ans = max(ans, (int)pq1.size());
		
	}
	cout << ans;
}