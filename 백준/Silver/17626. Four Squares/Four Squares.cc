#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n, k, start, tmp;
  cin >> n;
  int *dp = new int[n+1];
  for(int i = 0; i<n; i++){
    dp[i] = 0;
  }
  dp[0] = 0, dp[1] = 1;

  for (int i = 2; i< n+1; i++){
    k = 4;
    tmp = (int)(pow(i,0.5))+1;
    for(int j = 1; j<tmp; j++){
      k = min(k,dp[i-j*j]);
    }
    dp[i] = k + 1;
  }
  cout << dp[n];
  return 0;
}