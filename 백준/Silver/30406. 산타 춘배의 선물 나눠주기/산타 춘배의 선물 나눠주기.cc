// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <cstdio>
// #include <cstring>
// #define endl "\n"

// using namespace std;
// using ll = long long;
// using pii = pair<int,int>;
// using pll = pair<long,long>;

// int t,w,num;
// int seq[1001];
// int dp[1001][31][2];

// int trial(int curT, int w, int x){
// 	if(curT == 0) return 0;
	
// 	int &ret = dp[curT][w][x];
// 	if(ret != -1) return ret;

// 	ret = 0;
// 	if(seq[curT]-1 == x){
// 		ret = max(ret,trial(curT-1,w,x)+1);
// 	}else{
// 		if(w>0) ret = max(ret,trial(curT-1,w-1,1-x)+1);
// 		else ret = max(ret,trial(curT-1,w,x));
// 	}
// 	return ret;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);cout.tie(NULL);

// 	memset(dp,-1,sizeof(dp));
// 	cin >> t >> w;
// 	for(int i = 1; i < t+1; i++){
// 		cin >> seq[i];
// 	}
// 	cout << max(trial(t,w,0),trial(t,w,1));
// }

#include <iostream>

using namespace std;
int arr[4];
int ans = 0;
int solve(int i, int j, int satis){
	while(arr[i]>0 && arr[j]>0){
		arr[i]--;
		arr[j]--;
		ans+=satis;
	}
	return 0;
}
int main(){
	int n,price;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> price;
		arr[price]++;
	}
	solve(0,3,3);
	solve(1,2,3);
	solve(0,2,2);
	solve(1,3,2);
	solve(0,1,1);
	solve(2,3,1);
	cout << ans;
}