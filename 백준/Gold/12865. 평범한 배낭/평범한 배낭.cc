#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> weight(n+1);
  vector<int> value(n+1);
  vector<vector <int>> dp(n+1, vector<int>(k+1)); 
  for(int i = 1; i < n+1; i++){
    cin >> weight[i] >> value[i];
  }

  for(int i = 1; i < n+1; i++){
    for(int j = 1; j < k+1; j++){
      if(j >= weight[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
      else dp[i][j] = dp[i-1][j];
    }
  }
  cout << dp[n][k];
}