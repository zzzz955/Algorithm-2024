#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int t, f;
unordered_map<string, int> G;
unordered_map<string, string> F;

string Find(const string& a) {
	if (F[a] == a) return a;
	return F[a] = Find(F[a]);
}

void Union(const string& a, const string& b) {
	string A = Find(a);
	string B = Find(b);
	if (F[A] == F[B]) return;
	F[B] = a;
	G[A] += G[B];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> f;
		G.clear();
		F.clear();

		int g = 1;
		while (f--) {
			string a, b; cin >> a >> b;
			if (a > b) swap(a, b);
			if (!G[a]) {
				G[a] = 1;
				F[a] = a;
			}
			if (!G[b]) {
				G[b] = 1;
				F[b] = b;
			}
			Union(a, b);
			cout << G[Find(F[b])] << "\n";
		}
	}
}