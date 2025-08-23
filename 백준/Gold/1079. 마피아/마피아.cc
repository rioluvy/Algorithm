#include<iostream>
#include<algorithm>
#define dead -1
using namespace std;

int n, figure[17], R[17][17], mafiaIdx, ans;

int findMax(){
  int idx = 0;
  for(int i = 0; i < n; i++){
    if(figure[idx] < figure[i]) idx = i;
  }
  return idx;
}

void trial(int alive, int night){
  if(alive == 1 || figure[mafiaIdx] == dead){
    ans = max(ans, night);
    return;
  }

  if(alive & 1){
    int tmpIdx = findMax();
    int tmpNum = figure[tmpIdx];
    figure[tmpIdx] = dead;
    trial(alive-1, night);
    figure[tmpIdx] = tmpNum;
  }
  else{
    for(int i = 0; i < n; i++){
      if(figure[i] == dead || i == mafiaIdx) continue;
      int tmpNum = figure[i];
      figure[i] = dead;
      for(int j = 0; j < n; j++){
        if(figure[j] == dead) continue;
        figure[j] += R[i][j];
      }
      trial(alive-1, night+1);

      for(int j = 0; j < n; j++){
        if(figure[j] == dead) continue;
        figure[j] -= R[i][j];
      }
      figure[i] = tmpNum;
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> figure[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> R[i][j];
    }
  }
  cin >> mafiaIdx;
  trial(n,0);
  cout << ans;
}