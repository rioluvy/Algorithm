#include <iostream>
#include <cstring>
using namespace std;

int n, info[15][15], dp[16][10][1<<15];

int trial(int artist, int price, int visited){
  if(visited == (1<<n)-1){
    return 1;
  }

  int &ret = dp[artist][price][visited];
  if(ret != -1) return ret;
  ret = 1;

  for(int i = 0; i < n; i++){
    if(!(visited & (1<<i)) && info[artist][i] >= price){
      ret = max(ret,trial(i,info[artist][i],visited|(1<<i))+1);
    }
  }
  return ret;
}

int main(){
  cin >> n;
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    for(int j = 0; j < n; j++){
      info[i][j] = s[j] - '0';
    }
  }
  memset(dp,-1,sizeof(dp));
  cout << trial(0,0,1);
}