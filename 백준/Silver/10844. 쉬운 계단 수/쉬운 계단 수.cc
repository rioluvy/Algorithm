#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define Mod 1000000000;

using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int **dp = new int*[n];
  for(int i = 0; i<n+1; i++){
    dp[i] = new int[10];
  }
  for(int i = 0; i<n; i++){
    for (int j = 0; j<10; j++){
      dp[i][j] = 0;
    }
  }

  for(int i = 1; i<10; i++){
    dp[0][i] = 1;
  }
  for(int i = 1; i < n; i++){
    for(int j = 0; j < 10; j++){
      if(j == 0) dp[i][j] = dp[i-1][1];
      else if(j == 9) dp[i][j] = dp[i-1][8];
      else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
      dp[i][j] %= Mod;
    }
  }
  int sum = 0;
  for(int i = 0; i<10; i++){
    sum = (sum + dp[n-1][i]) % Mod;
  }
  cout << sum;
}