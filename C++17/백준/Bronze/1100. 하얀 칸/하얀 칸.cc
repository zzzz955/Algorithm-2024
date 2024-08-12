#include <iostream>

using namespace std;

int main() {
	string chess[8];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cin >> chess[i];
		for (int j = 0; j < 8; j++) {
			if (i % 2 && j % 2 && chess[i][j] == 'F') cnt++;
			if (i % 2 == 0 && j % 2 == 0 && chess[i][j] == 'F') cnt++;
		}
	}
	cout << cnt;
}