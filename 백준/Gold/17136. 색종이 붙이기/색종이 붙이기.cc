#include <iostream>
#include <climits>
using namespace std;

int map[10][10], ans = INT_MAX;
int paper[6] = {0,5,5,5,5,5};

bool paintCheck(int x, int y, int k){
  for(int i = x; i < x+k; i++){
    for(int j = y; j < y+k; j++){
      if(!map[i][j]) return false;
    }
  }
  return true;
}

void paint(int x, int y, int size, int tmp){
  for(int i = x; i < x+size; i++){
    for(int j = y; j < y+size; j++){
      map[i][j] = tmp;
    }
  }
}

bool isPaint(){
  bool flag = true;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(map[i][j]) flag = false;
    }
  }
  return flag;
}

void trial(int cnt){
  if(isPaint()) {
    ans = min(ans,cnt);
    return;
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(map[i][j]){
        for(int k = 1; k <= 5; k++){
          if(!paper[k]) continue;
          if(i+k > 10 || j+k > 10) break;
          if(paintCheck(i,j,k)){
            paper[k]--;
            paint(i,j,k,0);
            trial(cnt+1);
            paper[k]++;
            paint(i,j,k,1);
          }
        }
        return;
      }
    }
  }
}

int main(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> map[i][j];
    }
  }
  trial(0);
  cout << (ans == INT_MAX ? -1 : ans);
}