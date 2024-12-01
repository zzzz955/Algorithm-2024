#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int n, m, ans, mc, mb;

queue<int> wait;
queue<int> used;
map<int, int> boxes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int a; cin >> a;
		mc = max(mc, a);
		wait.push(a);
	}

	boxes[0] = 1;
	cin >> m;
	while (m--) {
		int a; cin >> a;
		mb = max(mb, a);
		boxes[a]++;
	}

	if (mc < mb) {
		cout << -1;
		return 0;
	}

	while (++ans) {
		while (!wait.empty() && boxes.size() > 1) {
			int now = wait.front(); wait.pop();
			auto it = boxes.upper_bound(now);
			
			if ((*--it).first != 0 && (*it).first <= now) {
				(*it).second--;
				used.push(now);
				if (!(*it).second) boxes.erase(it);
			}
		}
		if (boxes.size() == 1) break;
		swap(wait, used);
	}
	cout << ans;
}