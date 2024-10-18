#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(string a, string b) {
    while ((int)a.size() < 4) a += a;
    while ((int)b.size() < 4) b += b;
    return a > b;
}

string solution(vector<int> numbers) {
    vector<string> answer;
    for (int i:numbers) answer.push_back(to_string(i));
    sort(answer.begin(), answer.end(), cmp);
    string ans = "";
    for (const string& s:answer) ans += s;
    if (ans[0] == '0') return "0";
    return ans;
}