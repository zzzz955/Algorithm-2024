#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> lst(10);
		for (int i = 0; i < 10; i++) {
			cin >> lst[i];
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (lst[j] < lst[j + 1]) {
					int temp = lst[j];
					lst[j] = lst[j + 1];
					lst[j + 1] = temp;
				}
			}
		}
		cout << lst[2] << "\n";
	}
}