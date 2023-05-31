#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"

using namespace std;
int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s, w;
  cin >> s >> w;
  int s_length = s.length();
  int w_length = w.length();
  int dp[1001][1001];
  for(int i = 0 ; i < w_length+1; i++){
    for(int j = 0; j < s_length+1; j++){
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(s[j-1] == w[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp[w_length][s_length];
}