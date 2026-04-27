#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<ll> cnt(n+1,0);
	for(int i = 2; i < n+1; i++){
		cnt[i] = cnt[i-1]+(i-1);
	}

	ll ans = 0;
	int l = 0;
	vector<int> save(n+1,0);
	for(int i = 0; i < n; i++){
		cin >> save[i];
		if(l == 0 || save[i] > save[i-1]){
			l++;
			continue;
		}
		ans += cnt[l];
		l = 1;
	}
	ans += cnt[l];
	ans += n;
	cout << ans;
	
}