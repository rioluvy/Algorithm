#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;


int n;
vector<pii> G[5001];

ll trial(int cur, int par) {
	ll ret = 0;
	for (auto& p : G[cur]) {
		if (p.first == par) continue;
		ret = max(ret, trial(p.first, cur) + p.second);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, w; cin >> x >> y >> w;
		G[x].push_back({y,w});
		G[y].push_back({x,w});
	}

	cout << trial(1, 0);
}