#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int n, p, l, m;
struct ASC {
	int idx, dif;
	bool operator<(const ASC& other) const {
		if (dif == other.dif) return idx > other.idx;
		return dif > other.dif;
	}
};
struct DESC {
	int idx, dif;
	bool operator<(const DESC& other) const {
		if (dif == other.dif) return idx < other.idx;
		return dif < other.dif;
	}
};
unordered_map<int, int> dic;
priority_queue<ASC> pq_asc;
priority_queue<DESC> pq_desc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> p >> l;
		dic[p] = l;
		pq_asc.push({ p, l });
		pq_desc.push({ p, l });
	}

	cin >> m;
	while (m--) {
		string op; cin >> op;
		if (op == "add") {
			cin >> p >> l;
			dic[p] = l;
			pq_asc.push({ p, l });
			pq_desc.push({ p, l });
		}
		else if (op == "recommend") {
			int x; cin >> x;
			if (x == 1) {
				while (!pq_desc.empty()) {
					DESC desc = pq_desc.top();
					if (!dic[desc.idx] || dic[desc.idx] != desc.dif) pq_desc.pop();
					else break;
				}
				cout << pq_desc.top().idx << "\n";
			}
			else {
				while (!pq_asc.empty()) {
					ASC asc = pq_asc.top();
					if (!dic[asc.idx] || dic[asc.idx] != asc.dif) pq_asc.pop();
					else break;
				}
				cout << pq_asc.top().idx << "\n";
			}
		}
		else {
			int x; cin >> x;
			dic.erase(x);
		}
	}
}