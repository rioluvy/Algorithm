#include <iostream>
#include <cstring>
using namespace std;

int n, m, c, info[14], dp[10][21][1<<13];

int trial(int cur,int weight, int visited){
  bool flag = false;
  if(cur == m) return 0;

  int &ret = dp[cur][weight][visited];
  if(ret != -1) return ret;
  ret = 0;

  for(int i = 0; i < n; i++){
    if(visited&(1<<i)) continue;
    if(weight + info[i] > c) continue;
    else{
      flag = true;
      ret = max(ret, trial(cur, weight+info[i], visited|(1<<i))+1);
    }
  }
  if(!flag) ret = max(ret,trial(cur+1, 0, visited));
  return ret;
}


int main(){
  cin >> n >> m >> c;
  for(int i = 0; i < n; i++) cin >> info[i];
  memset(dp,-1,sizeof(dp));
  cout << trial(0,0,0);
}