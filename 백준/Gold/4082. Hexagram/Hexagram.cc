#include <iostream>
#include <cstring>
using namespace std;

int star[12], selected[12], visited[12], ans;
int line[6][4] = {
  {0,2,5,7},
  {1,2,3,4},
  {0,3,6,10},
  {7,8,9,10},
  {1,5,8,11},
  {4,6,9,11}
};
int order[12] = {0,2,5,7,3,6,10,1,4,8,9,11};

bool check(){
  int sum = selected[0] + selected[2] + selected[5] + selected[7];
  for(int i = 0; i < 6; i++){
    int tmpSum = 0;
    for(int j = 0; j < 4; j++){
      tmpSum += selected[line[i][j]];
    }
    if(sum != tmpSum) return false;
  }
  return true;
}

bool lineFull(int idx){
  for(int i = 0; i < 4; i++){
    if(!selected[line[idx][i]]) return false;
  }
  return true;
}

bool pruning(int sum){
  for(int i = 0; i < 6; i++){
    if(lineFull(i)){
      int tmpSum = 0;
      for(int j = 0; j < 4; j++){
        tmpSum += selected[line[i][j]];
      }
      if(tmpSum != sum) return true;
    }
  }
  return false;
}

void trial(int cnt, int idx){
  if(cnt == 12){
    if(check()) {
      ans++;
    }
    return;
  }
  if(selected[order[idx]] != 0){
    trial(cnt+1,idx+1);
    return;
  }
  for(int i = 0; i < 12; i++){
    if(!visited[i]){
      selected[order[idx]] = star[i];
      visited[i] = 1;

      if(selected[0] && selected[2] && selected[5] && selected[7]){
        int sum = selected[0] + selected[2] + selected[5] + selected[7];
        if(pruning(sum)){
          selected[order[idx]] = 0;
          visited[i] = 0;
          continue;
        }
      }
      trial(cnt+1,idx+1);
      visited[i] = 0;
      selected[order[idx]] = 0;
    }
  }
}


int main(){
  ios_base :: sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  while(true){
    ans = 0;
    bool flag = true;
    for(int i = 0; i < 12; i++){
      cin >> star[i];
      if(star[i] != 0) flag = false;
    }
    if(flag) break;

    memset(selected,0,sizeof(selected));
    memset(visited,0,sizeof(visited));
    selected[0] = star[0];
    visited[0] = 1;
    trial(0,order[0]);

    memset(selected,0,sizeof(selected));
    memset(visited,0,sizeof(visited));
    selected[2] = star[0];
    visited[0] = 1;
    trial(0,order[0]);

    cout << ans/2 << "\n";
  }
  return 0;
}