#include<iostream>
#include<vector>
using namespace std;

int n, a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	vector<int> result;

	int temp = n - a - b + 1;
	if (a >= b) {
		result.push_back(1);
		while (temp-- > 0) result.push_back(1);
		for (int i = 2; i <= a; i++) result.push_back(i);
		for (int i = b - 1; i > 0; i--) result.push_back(i);
	}
	else {
		int flag = 0;
		if (a > 1) {
			result.push_back(1);
			flag = 1;
		}
		else result.push_back(b);
		while (temp-- > 0) result.push_back(1);
		for (int i = 2; i < a; i++) result.push_back(i);
		if (flag) for (int i = b; i > 0; i--) result.push_back(i);
		else for (int i = b - 1; i > 0; i--) result.push_back(i);
	}

	if (result.size() == n) for (int i : result) cout << i << " ";
	else cout << -1;
}