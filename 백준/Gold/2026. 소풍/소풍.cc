#include <iostream>
using namespace std;

int k,n,f,a,b,cnt,e;
bool isFriends[901][901];
bool isTaken[901];

int trial(int val, int cnt){
  if(e) return 0;
  if(cnt==k){
    for(int i = 1; i <= n; i++){
      if(isTaken[i]) cout << i << "\n";
    }
    e = 1;
    return 0;
  }
  for(int i = val+1; i <= n; i++){
    if(!isFriends[val][i]) continue;
    bool flag = true;
    for(int j = 1; j <= n; j++){
      if(isTaken[j]){
        if(!isFriends[j][i]) flag = false;
      }
    }
    if(flag){
      isTaken[i] = true;
      trial(i, cnt+1);
    }
    isTaken[i] = false;
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> k >> n >> f;
  for(int i = 0; i < f; i++){
    cin >> a >> b;
    isFriends[a][b] = isFriends[b][a] = true;
  }

  for(int i = 1; i <= n; i++){
    isTaken[i] = true;
    trial(i, 1);
    isTaken[i] = false;
  }
  if(!e) cout << -1;
  return 0;
}