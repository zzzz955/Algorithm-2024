#include<iostream>

using namespace std;

int nums[100];
int op[4];
int n, min_val = 2e9, max_val = -2e9;

void bt(int level, int val) {
	if (level == n - 1) {
		min_val = min(min_val, val);
		max_val = max(max_val, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			if (i == 0) bt(level + 1, val + nums[level + 1]);
			if (i == 1) bt(level + 1, val - nums[level + 1]);
			if (i == 2) bt(level + 1, val * nums[level + 1]);
			if (i == 3) bt(level + 1, val / nums[level + 1]);
			op[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	cin >> op[0] >> op[1] >> op[2] >> op[3];
	bt(0, nums[0]);
	cout << max_val << "\n" << min_val << "\n";
}