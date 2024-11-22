#include<iostream>
#include<cmath>
#include<unordered_map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int n;
int values[100];
unordered_map<char, int> dic;
string words[10];
struct Prio {
	char c;
	int val;
	bool operator<(const Prio& other) const {
		return val < other.val;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		words[i] = s;
		reverse(s.begin(), s.end());
		for (int j = 0; j < s.size(); ++j) dic[s[j]] += pow(10, j);
	}

	priority_queue<Prio> pq;
	for (const auto& d : dic) pq.push({ d.first, d.second });

	char top = '9';
	while (!pq.empty()) {
		Prio prio = pq.top(); pq.pop();
		values[prio.c] = top--;
	}

	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < words[i].size(); ++j) words[i][j] = values[words[i][j]];
		result += stoi(words[i]);
	}

	cout << result;
}