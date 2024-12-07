#include<iostream>
#include<queue>
using namespace std;

int n, ans;
priority_queue<int> p;
priority_queue<int, vector<int>, greater<int>> m;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		if (num <= 0) m.push(num);
		else p.push(num);
	}

	while (!p.empty()) {
		int num = p.top(); p.pop();
		if (!p.empty()) {
			int tied = num * p.top();
			if (tied > num + p.top()) {
				ans += tied;
				p.pop();
				continue;
			}
		}
		ans += num;
	}

	while (!m.empty()) {
		int num = m.top(); m.pop();
		if (!m.empty()) {
			int tied = num * m.top();
			if (tied > num + m.top()) {
				ans += tied;
				m.pop();
				continue;
			}
		}
		ans += num;
	}
	cout << ans;
}