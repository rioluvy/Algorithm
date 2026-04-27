#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll n, k, a, b;
	cin >> n >> k;
	vector<ll> diff;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a>=b) cnt++;
		else diff.push_back((a-b));
	}
	if(k<=cnt){
		cout << 0;
	}else{
		sort(diff.rbegin(),diff.rend());
		ll left = k-cnt;
		cout << -(diff[left-1]);
	}
	
}