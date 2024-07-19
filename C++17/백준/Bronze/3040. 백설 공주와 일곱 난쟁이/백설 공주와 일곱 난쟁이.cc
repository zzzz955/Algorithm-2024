#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> lst(9);

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> lst[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				for (int l = k + 1; l < 9; l++) {
					for (int m = l + 1; m < 9; m++) {
						for (int n = m + 1; n < 9; n++) {
							for (int o = n + 1; o < 9; o++) {
								if (lst[i] + lst[j] + lst[k] + lst[l] + lst[m] + lst[n] + lst[o] == 100) {
									cout << lst[i] << "\n";
									cout << lst[j] << "\n";
									cout << lst[k] << "\n";
									cout << lst[l] << "\n";
									cout << lst[m] << "\n";
									cout << lst[n] << "\n";
									cout << lst[o] << "\n";
								}
							}
						}
					}
				}
			}
		}
	}
}