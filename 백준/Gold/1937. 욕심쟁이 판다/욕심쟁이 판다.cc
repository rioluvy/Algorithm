#include<iostream>
using namespace std;

int n, forest[501][501], dp[501][501], ans = 1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int trial(int x, int y){
  if(dp[x][y] != 0) return dp[x][y];
  int &ret = dp[x][y];
  ret = 1;

  for(int d = 0; d < 4; d++){
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if(forest[x][y] >= forest[nx][ny]) continue;
    ret = max(ret, trial(nx,ny)+1);
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> forest[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans,trial(i,j));
    }
  }
  cout << ans;
}