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
  string first, second, third;
  cin >> first >> second >> third;
  int f_length = first.length();
  int s_length = second.length();
  int t_length = third.length();
  int dp[101][101][101];
  for(int i = 0; i < s_length+1; i++){
    for(int j = 0; j < f_length+1; j++){
      for(int k = 0; k < t_length+1; k++){
        if (i == 0 || j == 0 || k == 0) {
          dp[i][j][k] = 0;
          continue;
        }
        if(second[i-1] == first[j-1] && first[j-1] ==  third[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
      }
    }
  }
  cout << dp[s_length][f_length][t_length];
	
	return 0;
}