#include <iostream>
#include <algorithm>
#include <cmath>

int main(){

  int n, k, start;
  std::cin >> n;
  int *dp = new int[n+1];
  for(int i = 0; i<n; i++){
    dp[i] = 0;
  }
  dp[0] = 0, dp[1] = 1;

  for (int i = 2; i< n+1; i++){
    k = 4;
    for(int j = 1; j<(int)(pow(i,0.5))+1;j++){
      k = std::min(k,dp[i-j*j]);
      
    }
    dp[i] = k + 1;
  }
  std::cout << dp[n];
  return 0;
}