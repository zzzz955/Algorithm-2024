#include<iostream>
#include<vector>
using namespace std;

string s, Cstack;
vector<int> Nstack(1, 0);
int len;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == ')') {
			Nstack.push_back(0);
		}
		else if (s[i] == '(') {
			Cstack.push_back(s[i]);
		}
		else {
			if (!Cstack.empty()) {
				Cstack.pop_back();
				Nstack.back() *= s[i] - '0';
				int res = Nstack.back();
				Nstack.pop_back();
				Nstack.back() += res;
			}
			else Nstack.back()++;
		}
	}
	int sum = 0;
	for (int i : Nstack) sum += i;
	cout << sum;
}