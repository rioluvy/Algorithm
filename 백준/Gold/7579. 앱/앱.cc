#include<iostream>
#include<cstring>
#define impossible -2100000000
using namespace std;

int n, M, m[101], c[101], cache[101][10001];

int trial(int idx, int cost){
  if(cost < 0) return impossible;
  if(idx < 0) return 0;

  int& ret = cache[idx][cost];
  if(ret != -1) return ret;

  ret = trial(idx-1,cost);
  ret = max(ret,trial(idx-1,cost-c[idx])+m[idx]);
  return ret;
}

int main(){
  cin >> n >> M;
  for(int i = 0; i < n; i++)
    cin >> m[i];
  for(int i = 0; i < n; i++)
    cin >> c[i];
  memset(cache,-1,sizeof(cache));

  int maxCost = 100*n;
  int ans = maxCost;
  for(int i = 0; i <= maxCost; i++){
    if(trial(n-1,i) >= M){
      ans = i;
      break;
    }
  }
  cout << ans;
}