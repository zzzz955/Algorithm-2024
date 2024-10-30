#include<iostream>
#include<algorithm>
using namespace std;

int h, w, f, ans;
int nodes[555];

int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) cin >> nodes[i];
	for (int i = 2; i < w; i++) {
		int *l = max_element(nodes, nodes + i);
		int *r = max_element(nodes + i + 1, nodes + w + 1);
		
		ans += max(0, min(*l, *r) - nodes[i]);
	}
	cout << ans;
}