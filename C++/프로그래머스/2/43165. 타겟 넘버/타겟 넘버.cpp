#include <string>
#include <vector>

using namespace std;

int n, ans, t, total;

void bt(int level, int val, int remain, const vector<int>& numbers) {
    if (level == n) {
        if (val == t) ans++;
        return;
    }
    
    if (val + remain < t) return;
    if (val - remain > t) return;
    
    bt(level + 1, val + numbers[level], remain - numbers[level], numbers);
    bt(level + 1, val - numbers[level], remain - numbers[level], numbers);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    for (int i:numbers) total += i;
    t = target;
    bt(0, 0, total, numbers);
    return ans;
}