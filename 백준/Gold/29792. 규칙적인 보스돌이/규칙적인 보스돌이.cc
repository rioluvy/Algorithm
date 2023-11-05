#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(NULL);cout.tie(NULL);
		ll n,m,k,hp,meso,clearTime;
		cin >> n >> m >> k;
		ll damage[50];
		ll dp[50][901];
		vector<pll> boss;
		vector<ll> arr;
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++){
				cin >> damage[i];
		}
		for(int i = 0; i < k; i++){
				cin >> hp >> meso;
				boss.push_back({hp,meso});
		}

		for(int i = 0; i < n; i++){
				for(int j = 0; j < k; j++){
						ll time = boss[j].first/damage[i];
						clearTime = ((boss[j].first%damage[i] > 0) ? time+1:time);
						for(int l = 900; l-clearTime >=0 ; l--){
								dp[i][l] = max(dp[i][l],dp[i][l-clearTime]+boss[j].second);
						}
				}
		}
		for(int i = 0; i < n; i++){
				arr.push_back(dp[i][900]);
		}
		sort(arr.begin(),arr.end());
		ll total = 0;
		for(int i = n-1; i >= n-m; i--){
				total += arr[i];
		}
		cout << total;
}