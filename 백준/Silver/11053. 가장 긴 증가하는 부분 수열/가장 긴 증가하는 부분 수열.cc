#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> sequence(n+1,1);
  vector<int> dp(1001,1);
  for(int i = 1; i < n+1; i++){
    cin >> sequence[i];
  }

  for(int i = 1; i < n+1; i++){
    for(int j = 1; j < i; j++){
      if (sequence[i] > sequence[j]) dp[i] = max(dp[i], dp[j]+1);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
  return 0;
}