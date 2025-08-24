#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, m;
	cin >> n;
	vector<int> v1(n);
	for (auto &v : v1) cin >> v;
	sort(v1.begin(), v1.end()); 

	cin >> m;
	vector<pii> v2;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		v2.push_back({tmp, i});
	}
	sort(v2.begin(), v2.end()); 

	vector<int> ans(m);
	int i = 0, j = 0;

	while (i < n && j < m) {
		if (v1[i] < v2[j].first) i++;
		
		else if (v1[i] > v2[j].first) j++;
		else { 
			int target = v1[i];
			int cnt = 0;
			while (i < n && v1[i] == target) {
					cnt++; 
					i++;
			}

			while (j < m && v2[j].first == target) {
					ans[v2[j].second] = cnt;
					j++;
			}
		}
	}

	for (int k = 0; k < m; k++) {
		cout << ans[k] << " ";
	}
}
