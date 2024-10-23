#include<iostream>
#include<deque>

using namespace std;

int n, total, ans;
int kit[200000];

struct Node{
	int cnt, idx;
};

deque<Node> deq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> kit[i];
		total += kit[i];
	}

	int div = total / n;
	for (int i = 0; i < n; i++) {
		if (kit[i] > div) deq.push_back({ kit[i] - div, i });
	}

	for (int i = 0; i < n; i++) {
		if (kit[i] < div) {
			while (!deq.empty() && kit[i] < div) {
				Node node = deq.front(); deq.pop_front();
				int cnt = node.cnt, idx = node.idx;
				int need = min(div - kit[i], cnt);
				kit[i] += need;
				ans += need * (abs(i - idx));
				cnt -= need;
				if (cnt) deq.push_front({ cnt, idx });
			}
		}
	}
	cout << ans;
}