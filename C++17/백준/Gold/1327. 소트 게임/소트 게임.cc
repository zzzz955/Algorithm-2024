#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<string>

using namespace std;

int n, k;
string input = "", s = "", e = "";
unordered_map<string, int> v;

struct Now {
	string cur;
	int t;
};

string Reverse(string num, int index) {
	string new_string = num.substr(index, k);
	reverse(new_string.begin(), new_string.end());
	num.replace(num.begin() + index, num.begin() + index + k, new_string);
	return num;
}

int bfs() {
	queue<Now> q;
	q.push({ s, 0 });
	v[s] = 1;

	while (!q.empty()) {
		Now now = q.front(); q.pop();
		string num = now.cur;
		int t = now.t;
		if (num == e) return t;
		for (int i = 0; i <= n - k; i++) {
			string result = Reverse(num, i);
			if (!v[result]) {
				v[result] = 1;
				q.push({ result, t + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		input += c;
	}
	s = input;
	sort(input.begin(), input.end());
	e = input;
	cout << bfs();
}