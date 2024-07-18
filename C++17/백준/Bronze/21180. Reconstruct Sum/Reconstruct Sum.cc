#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int sum = 0;
	int ans = 100001;
	cin >> n;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		sum += lst[i];
	}
	for (int i = 0; i < n; i++) {
		if (lst[i] == sum - lst[i]) {
			ans = lst[i];
			break;
		}
	}
	if (ans < 100001) {
		cout << ans;
	}
	else {
		cout << "BAD";
	}
}

