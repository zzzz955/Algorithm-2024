#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, nums[1000000];

int BS() {
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
		if (it == temp.end()) temp.push_back(nums[i]);
		else *it = nums[i];
	}
	return temp.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << BS();
}