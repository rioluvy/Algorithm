#include <stdio.h>
#include <cstring>
#define INF 10000

template<typename T>
T min(T a, T b){
  return (a<b ? a:b);
}

int n, p, onPlant, plant[16][16], dp[1<<16];
char c;

int trial(int onPlant){
  if(__builtin_popcount(onPlant) >= p)
    return 0;

  int &ret = dp[onPlant];
  if(ret != -1) return ret;
  ret = INF;
  for(int i = 0; i < n; i++){
    if(!(onPlant & (1<<i))){
      for(int j = 0; j < n; j++){
        if(onPlant & (1<<j)){
          ret = min(ret, trial(onPlant|(1<<i))+plant[j][i]);
        }
      }
    }
  }
  return dp[onPlant];
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &plant[i][j]);
    }
  }
  for(int i = 0; i < n; i++){
    scanf(" %c", &c);
    onPlant |= (c == 'Y' ? (1<<i):0);
  }
  scanf("%d", &p);
  if(!p){
    printf("0\n");
    return 0;
  }
  memset(dp,-1,sizeof(dp));
  int ans = trial(onPlant);
  printf("%d", ans == INF ? -1:ans);
}