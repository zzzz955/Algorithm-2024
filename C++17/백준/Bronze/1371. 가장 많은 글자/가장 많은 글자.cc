#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> vat(255, 0);
	int max_val = -1;
	int turn = 50;
	while (turn--) {
		try
		{
			string s;
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {
				if (97 <= s[i] && s[i] < 123) {
					vat[s[i]]++;
					if (vat[s[i]] > max_val) max_val = vat[s[i]];
				}
			}
		}
		catch (const std::exception&)
		{
			break;
		}
	}
	for (int i = 97; i < 123; i++) {
		if (max_val == vat[i]) {
			cout << (char)i;
		}
	}
}