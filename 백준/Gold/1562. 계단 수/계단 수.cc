#include <iostream>
#include <cstring>
#include <cmath>
#define ll long long
#define mod 1000000000
using namespace std;

int n;
ll ans, dp[10][100][1<<10];

ll trial(int curNum, int curN, int visited){
  if(curN == n-1){
    return (visited == (1<<10)-1) ? 1:0;
  }
  ll &ret = dp[curNum][curN][visited];
  if(ret != -1) return ret;
  ret = 0;

  for(int i = 0; i < 10; i++){
    if(abs(i-curNum) == 1){
      ret += trial(i, curN+1, visited|(1<<i));
      ret %= mod;
    }
  }
  return ret;
}

int main(){
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(int i = 1; i < 10; i++){
    ans += trial(i,0,(1<<i));
    ans %= mod;
  }
  cout << ans;
}