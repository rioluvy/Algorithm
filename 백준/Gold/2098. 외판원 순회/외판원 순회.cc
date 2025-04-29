#include <iostream>
#include <cstring>
#define INF 100000000
using namespace std;

int n, w[16][16], dp[16][65536];

int trial(int cur, int visited){
  if(visited == (1<<n)-1){
    return (w[cur][0] == 0 ? INF : w[cur][0]);
  }
  if(dp[cur][visited] != -1) return dp[cur][visited];

  dp[cur][visited] = INF;
  for(int i = 0; i < n; i++){
    if(!((1<<i) & visited) && w[cur][i] != 0){
      dp[cur][visited] = min(trial(i,visited|(1<<i)) + w[cur][i], dp[cur][visited]);
    }
  }
  return dp[cur][visited];
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> w[i][j];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout << trial(0,1);
}