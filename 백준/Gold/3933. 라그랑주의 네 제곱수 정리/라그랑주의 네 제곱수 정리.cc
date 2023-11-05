#include <iostream>
#include <cstring>
#define endl "\n"
using namespace std;
int main(){
	int dp[32769][5];
	memset(dp,0,sizeof(dp));
	for(int i = 1; i < 5; i++){
		dp[0][i] = 1;
	}
	for(int i = 1; i*i < 32769; i++){
		dp[i*i][1] = 1;
		for(int j = i*i; j < 32769; j++){
			dp[j][2] += dp[j-i*i][1];
			dp[j][3] += dp[j-i*i][2];
			dp[j][4] += dp[j-i*i][3];
		}
	}
	int n;
	while(cin >> n){
		if(!n) break;
		cout << dp[n][4] << endl;
	}
}