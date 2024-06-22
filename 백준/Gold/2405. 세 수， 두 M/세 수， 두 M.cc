#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, avg, ans, tmp;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	ans = -1;
	for(int i = 1; i < n-1; i++){
		avg = v[0] + v[i] + v[i+1];
		tmp = abs(avg-3*v[i]);
		ans = max(tmp, ans);
	}
	for(int i = 0; i < n-2; i++){
		avg = v[i] + v[i+1] + v[n-1];
		tmp = abs(avg-3*v[i+1]);
		ans = max(tmp, ans);
	}
	cout << ans;
}