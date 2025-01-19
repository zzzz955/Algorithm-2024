#include<iostream>
#include<deque>
#include<algorithm>
#define ll long long
using namespace std;

int n, d;
ll lst[100000];

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	deque<pair<int, ll>> deq;
	for (int i = 0; i < n; ++i) {
		while (!deq.empty()) {
			if (deq.front().first < i - d) deq.pop_front();
			else {
				lst[i] = max(lst[i], lst[i] + deq.front().second);
				break;
			}
		}
		while (!deq.empty()) {
			if (deq.back().second < lst[i]) deq.pop_back();
			else break;
		}
		deq.push_back({ i, lst[i] });
	}
	cout << *max_element(lst, lst + n);
}