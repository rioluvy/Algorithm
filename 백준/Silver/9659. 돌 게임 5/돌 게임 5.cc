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
using ll = long long;
int main(){
	ll n;
	cin >> n;
	if(n%2==0) cout << "CY";
	else cout << "SK";
}