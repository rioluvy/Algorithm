#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int dp[16];
  memset(dp,0,sizeof(dp));
  int* T = new int[n+1];
  int* P = new int[n+1];
  for(int i = 1; i < n+1; i++){
    cin >> T[i];
    cin >> P[i];
    if(i + T[i] <= n+1) dp[i] = P[i];
  }

  for(int i = 1; i < n+1; i++){
    for(int j = i + T[i]; j< n+1; j++){
      if((T[j] + j <= n+1) && (dp[j] < dp[i] + P[j])){
        dp[j] = dp[i] + P[j];
      }
    }
  }
  cout << *max_element(begin(dp), end(dp));
}