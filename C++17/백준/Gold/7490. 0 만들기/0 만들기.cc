#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
vector<string> ans;
vector<char> ops;

int calc() {
	vector<int> nums(1, 1);
	for (int i = 2; i <= n; i++) {
		if (ops[i - 2] == ' ') {
			int temp = nums.back();
			nums.pop_back();
			nums.push_back(temp * 10 + i);
		}
		else nums.push_back(i);
	}

	int sum = nums[0];
	int idx = 1;
	for (int i = 0; i < n - 1; i++) {
		if (ops[i] == '+') sum += nums[idx++];
		else if (ops[i] == '-') sum -= nums[idx++];
	}
	return sum;
}

void bt(int level) {
	if (level == n) {
		if (!calc()) {
			string temp = "1";
			for (int i = 0; i < n - 1; i++) {
				temp += ops[i];
				temp += i + '2';
			}
			ans.push_back(temp);
		}
		return;
	}

	ops.push_back('+');
	bt(level + 1);
	ops.pop_back();

	ops.push_back('-');
	bt(level + 1);
	ops.pop_back();

	ops.push_back(' ');
	bt(level + 1);
	ops.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		ans.clear();
		ops.clear();
		bt(1);
		sort(ans.begin(), ans.end());
		for (const string& s : ans) cout << s << "\n";
		cout << "\n";
	}
}