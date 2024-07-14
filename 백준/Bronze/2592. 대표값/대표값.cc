#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, i, j;
	int sum = 0;
	int nums[10];
	for (i = 0; i < 10; i++) {
		cin >> nums[i];
	}
	int max_cnt = 0;
	int max_val = 0;
	for (i = 0; i < 10; i++) {
		sum += nums[i];
		int cnt = 0;
		for (j = 0; j < 10; j++) {
			if (nums[i] == nums[j]) cnt++;
		}
		if (max_cnt < cnt) {
			max_cnt = cnt;
			max_val = nums[i];
		}
	}
	cout << sum / 10 << "\n";
	cout << max_val;
}