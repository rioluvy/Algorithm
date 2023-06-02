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
  ios::sync_with_stdio(0); cin.tie(0);
  string first, second;
  cin >> first >> second;
  int f_length = first.length();
  int s_length = second.length();
  int dp[1001][1001];
  for(int i = 0; i < s_length+1; i++){
    for(int j = 0; j < f_length+1; j++){
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if(second[i-1] == first[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  string ans = "";
	int i = s_length, j = f_length;
	while (dp[i][j] != 0){
		if(dp[i][j] == dp[i][j-1])
			j--;
		else if(dp[i][j] == dp[i-1][j])
			i--;
		else{
			ans += first[j-1];
			i--;j--;
		}
		
	}
	reverse(ans.begin(),ans.end());
	
  cout << dp[s_length][f_length] << endl << ans;
}