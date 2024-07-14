#include <iostream>
#include <vector>

using namespace std;

int main() {
	int lst[5][4];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> lst[i][j];
		}
	}
	int max_index = 0;
	int max_val = 0;
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			temp += lst[i][j];
		}
		if (temp > max_val) {
			max_val = temp;
			max_index = i + 1;
		}
	}
	cout << max_index << " " << max_val;
}