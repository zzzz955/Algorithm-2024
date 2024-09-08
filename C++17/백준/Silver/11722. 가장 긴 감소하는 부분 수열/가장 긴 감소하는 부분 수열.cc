#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, nums[1000000];
vector<int> temp;

void BS() {
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
		if (it == temp.end()) temp.push_back(nums[i]);
		else *it = nums[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		nums[i] = -a;
	}
	BS();
	cout << temp.size() << "\n";
}