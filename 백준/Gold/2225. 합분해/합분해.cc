#include <iostream>
#include <cstring>
#define mod 1000000000
#define endl "\n"
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int dp[201][201];
    memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
 	for(int i = 1; i < k+1; i++){
		for(int j = 0; j < n+1; j++){
			for(int l = 0; l <= j; l++){
				dp[j][i] = (dp[j][i]+dp[l][i-1])%mod;
			}
		}
	}
	cout << dp[n][k];
}