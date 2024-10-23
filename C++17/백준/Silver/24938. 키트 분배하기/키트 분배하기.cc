#include<iostream>
#include<deque>
#define ll long long

using namespace std;

ll n, total, ans;
ll kit[200000];

struct Node{
	ll cnt, idx;
};

deque<Node> deq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> kit[i];
		total += kit[i];
	}

	ll div = total / n;
	for (int i = 0; i < n; i++) {
		if (kit[i] > div) deq.push_back({ kit[i] - div, i });
	}

	for (int i = 0; i < n; i++) {
		if (kit[i] < div) {
			while (!deq.empty() && kit[i] < div) {
				Node node = deq.front(); deq.pop_front();
				ll cnt = node.cnt, idx = node.idx;
				ll need = min(div - kit[i], cnt);
				kit[i] += need;
				kit[idx] -= need;
				ans += need * (abs(i - idx));
				cnt -= need;
				if (cnt) deq.push_front({ cnt, idx });
			}
		}
	}
	cout << ans;
}