#include <iostream>
#include <string>

using namespace std;

int main() {
	while (1) {
		try
		{
			string s;
			getline(cin, s);
			if (s == "") break;
			int small = 0, big = 0, num = 0, black = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') black++;
				else if (s[i] < 65) num++;
				else if (s[i] < 97) big++;
				else small++;
			}
			cout << small << " " << big << " " << num << " " << black << "\n";
		}
		catch (const std::exception&)
		{
			break;
		}
	}
}