#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n+1);
	vector<int> reverseArr(n+1);
	for(int i = 1; i < n+1; i++){
		cin >> arr[i];
		reverseArr[n-i+1] = arr[i];
	}
	ll ans = -9223372036854775808;
	ll S = arr[1]-k;
	ll N = reverseArr[1]-k;
	for(int i = 2; i < n+1; i++) {
		S = min(S, (ll)(arr[i-1]-k*(i-1)));
		N = min(N, (ll)(reverseArr[i-1]-k*(i-1)));
		ans = max({ans, arr[i]-(k*i)-S, reverseArr[i]-(k*i)-N});
	}
	cout << ans;
}

