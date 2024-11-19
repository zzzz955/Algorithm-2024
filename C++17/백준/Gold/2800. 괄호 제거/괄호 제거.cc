#include<iostream>
#include<set>
#include<vector>
using namespace std;

int n, cnt;
vector<int> si;
vector<int> ei;
set<string> ans;
string s;

void bt(int level, string str) {
	if (level) {
		string temp = "";
		for (const char& ch : str) if (ch != ' ') temp += ch;
		ans.insert(temp);
	}
	if (level == cnt) return;
	
	bt(level + 1, str);
	str[si[level]] = ' ';
	str[ei[level]] = ' ';
	bt(level + 1, str);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	n = s.size();
	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') stack.push_back(i);
		else if (s[i] == ')') {
			si.push_back(stack.back());
			ei.push_back(i);
			stack.pop_back();
			cnt++;
		}
	}
	bt(0, s);
	ans.erase(s);
	for (const string r : ans) cout << r << "\n";
}