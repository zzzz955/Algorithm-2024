#include<iostream>
#include<queue>

using namespace std;

int n, v[100000];
string s, t1, t2;

struct Prio {
	char c;
	int index;
	bool operator<(const Prio& other) const {
		if (c == other.c) return index < other.index;
		return c > other.c;
	}
};

priority_queue<Prio> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		v[i] = 1;
		pq.push({ s[i], i });
	}

	int last_index = n - 1;
	while (n) {
		if (n % 2) {
			while (!pq.empty()) {
				Prio prio = pq.top(); pq.pop();
				if (!v[prio.index]) continue;
				v[prio.index] = 0;
				t2 += prio.c;
				break;
			}
		}
		else {
			while (last_index >= 0) {
				if (v[last_index]) {
					v[last_index] = 0;
					t1 += s[last_index--];
					break;
				}
				last_index--;
			}
		}
		n--;
	}
	int win = 0;
	if (t1 > t2) win = 1;
	if (win) cout << "DA\n";
	else cout << "NE\n";
	cout << t2;
}