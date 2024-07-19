#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> w(10);
	vector<int> k(10);
	for (int i = 0; i < 20; i++) {
		if (i < 10) cin >> w[i];
		else cin >> k[i - 10];
	}
	sort(w.begin(), w.end(), greater<int>());
	sort(k.begin(), k.end(), greater<int>());
	int sum_w = 0;
	int sum_k = 0;
	for (int i = 0; i < 3; i++) {
		sum_w += w[i];
		sum_k += k[i];
	}
	cout << sum_w << " " << sum_k;
}