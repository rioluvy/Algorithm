#include <iostream>

#include <algorithm>

#include <vector>

#include <cstring>

using namespace std;

int main() {

    int n,k;

    cin >> n >> k;

    int coin[101];

    for(int i=1;i<n+1;i++){

      cin >> coin[i];

    }

    int dp[100001];

    fill(dp,dp+100001,100001);

    for(int i=1;i<n+1;i++){

      dp[coin[i]] = 1;

      for(int j=coin[i];j<k+1;j++){

         dp[j] = min(dp[coin[i]] + dp[j-coin[i]],dp[j]);

      }

    }

    if (dp[k] == 100001) {dp[k] = -1;}

    cout << dp[k];

}