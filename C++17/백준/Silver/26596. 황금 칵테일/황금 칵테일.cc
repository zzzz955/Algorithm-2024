#include<iostream>
#include<unordered_map>

using namespace std;

int m;
const double gold_rate = 1.618;
unordered_map<string, int> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	while (m--) {
		string s; int v; cin >> s >> v;
		dic[s] += v;
	}
	int flag = 0;
	for (auto& val1 : dic) {
		for (auto& val2 : dic) {
			if ((int)(val1.second * gold_rate) == val2.second) {
				if (val1.first == val2.first) continue;
				flag = 1;
				break;
			}
		}
	}
	if (flag) cout << "Delicious!";
	else cout << "Not Delicious...";		
}