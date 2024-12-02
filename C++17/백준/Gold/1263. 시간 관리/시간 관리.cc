#include<iostream>
#include<queue>
using namespace std;

int n;
struct Job {
	int t, s;
	bool operator<(const Job& other) const {
		if (s == other.s) return t > other.t;
		return s < other.s;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<Job> pq;
	for (int i = 0; i < n; ++i) {
		int ti, si; cin >> ti >> si;
		pq.push({ ti, si });
	}
	
	int now = 1000001;
	while (!pq.empty()) {
		if (!pq.empty() && pq.top().s < now) now = pq.top().s;

		queue<int> q;
		while (!pq.empty() && pq.top().s >= now) {
			q.push(pq.top().t);
			pq.pop();
		}

		while (!q.empty()) {
			now -= q.front();
			q.pop();
		}
	}
	if (now >= 0) cout << now;
	else cout << -1;
}