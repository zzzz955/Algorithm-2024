#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string ans = "";
	for (int i = 0; i < 5; i++) {
		string agent;
		cin >> agent;
		if (agent.find("FBI") != agent.npos) ans += to_string(i + 1) + " ";
	}
	if (ans == "") cout << "HE GOT AWAY!";
	else cout << ans;
}