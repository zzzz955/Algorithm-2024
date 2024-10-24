#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    vector<char> stack;
    for (const char& ch : s) {
        if (ch == '(') stack.push_back(ch);
        else {
            if (stack.empty()) return false;
            else stack.pop_back();
        }
    }
    if (!stack.empty()) return false;

    return answer;
}