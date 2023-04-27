#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n, color;
  cin >> n;
  vector<vector <int>> house(n,vector<int>(3));
  vector<vector <int>> dp(n,vector<int>(3));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++){
      cin >> house[i][j];
    }
  }
  dp[0][0] = house[0][0];
  dp[0][1] = house[0][1];
  dp[0][2] = house[0][2];

  for(int i = 1; i < n; i++){
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
  }
  cout << *min_element(dp[n-1].begin(), dp[n-1].end());
}