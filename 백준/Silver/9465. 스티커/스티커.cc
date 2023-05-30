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
  int T,n;
  cin >> T;
  while(T--){
    cin >> n;
    int dp[2][100001];
    int first_line[100001];
    int second_line[100001];
    for(int i = 0 ; i < n; i++){
      cin >> first_line[i];
    }
    for(int i = 0 ; i < n; i++){
      cin >> second_line[i];
    }

    dp[0][0] = first_line[0];
    dp[1][0] = second_line[0];
    dp[0][1] = dp[1][0] + first_line[1];
    dp[1][1] = dp[0][0] + second_line[1];
    for(int i = 2; i < n; i++){
      dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + first_line[i];
      dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + second_line[i];
    }

    int ans = max(dp[0][n-1], dp[1][n-1]);
    cout << ans << endl;
  }
}