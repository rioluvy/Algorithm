#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define endl "\n"
using namespace std;

ll cal(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	
	ll k = cal(a, b / 2);
	if (b % 2 == 0) return k * k;
	return k * k * a;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		if(k > 60 || n < cal(2,k)){
			cout << 0 << endl;
			continue;
		}
		ll start = cal(2,k);
		ll plus = cal(2,k+1);
		ll ans = (n-start)/plus + 1;
		
		cout << ans << endl;
	}
}