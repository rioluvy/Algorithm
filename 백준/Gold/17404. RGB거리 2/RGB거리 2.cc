#include <iostream>

#include <algorithm>

#include <vector>

#include <limits.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;    int cost[2001][3];

    cin >> n;

    for(int i=1;i<n+1;i++){

      cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    }

    int dp[2001][3];

    int ans = INT_MAX-10000;

    

    for(int j=0;j<3;j++){

      for(int k=0;k<3;k++){

        if(j==k) dp[1][k]= cost[1][k];

        else dp[1][k]= INT_MAX-10000;

      }

      for(int i=2;i<n+1;i++){

        dp[i][0]= min(dp[i-1][1],dp[i-1][2]) + cost[i][0];

        dp[i][1]= min(dp[i-1][0],dp[i-1][2]) + cost[i][1];

        dp[i][2]= min(dp[i-1][1],dp[i-1][0]) + cost[i][2];

      }

      for(int i=0;i<3;i++){

        if (i==j) continue;

        ans=min(dp[n][i],ans);

      }

    }

    cout << ans;

}