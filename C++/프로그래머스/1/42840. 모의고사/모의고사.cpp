#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int aa, ba, ca;

vector<int> solution(vector<int> answers) {
    while (a.size() <= 10000) a += "12345";
    while (b.size() <= 10000) b += "21232425";
    while (c.size() <= 10000) c += "3311224455";
    
    int max_ans = 0;
    for (int i = 0; i < answers.size(); i++) {
        int temp = answers[i] + '0';
        if (a[i] == temp) aa++;
        if (b[i] == temp) ba++;
        if (c[i] == temp) ca++;
        max_ans = max({aa, ba, ca});
    }
    vector<int> answer;
    
    if (aa == max_ans) answer.push_back(1);
    if (ba == max_ans) answer.push_back(2);
    if (ca == max_ans) answer.push_back(3);
    
    return answer;
}