#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, max_lv, ans = -2e9;
string s;
vector<int> nums;
vector<char> ops;

void init() {
	for (int i = 0; i < n; i++) {
		if (i % 2) ops.push_back(s[i]);
		else nums.push_back(s[i] - '0');
	}
}

int chk(const vector<int>& path) {
	vector<int> tn = nums;
	vector<char> to = ops;
	for (int i : path) {
		char op = to[i];
		if (op == '+') tn[i] += tn[i + 1];
		else if (op == '-') tn[i] -= tn[i + 1];
		else tn[i] *= tn[i + 1];
		to[i] = ' ';
	}
	
	int sum = tn[0];
	for (int i = 0; i < max_lv; i++) {
		char op = to[i];
		if (op == ' ') continue;
		else if (op == '+') sum += tn[i + 1];
		else if (op == '-') sum -= tn[i + 1];
		else sum *= tn[i + 1];
	}
	return sum;
}

void bt(int level, vector<int> path) {
	if (level == max_lv) {
		ans = max(ans, chk(path));
		return;
	}

	bt(level + 1, path);
	if (path.empty()) {
		path.push_back(level);
		bt(level + 1, path);
	}
	else if (path.back() < level - 1) {
		vector<int>new_path = path;
		new_path.push_back(level);
		bt(level + 1, new_path);
	}
}

int main() {
	cin >> n >> s;

	init();
	max_lv = n / 2;
	vector<int> path;
	bt(0, path);
	cout << ans;
}