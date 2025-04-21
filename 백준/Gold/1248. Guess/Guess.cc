#include <iostream>
#include <cstdlib>
using namespace std;

int n, ans[10];
char map[10][10];

bool check(int row){
  int psum = 0;
  for(int i = row; i >= 0 ; i--){
    psum += ans[i];
    if(map[i][row] == '+' && psum <= 0) return false;
    if(map[i][row] == '-' && psum >= 0) return false;
    if(map[i][row] == '0' && psum != 0) return false;
  }
  return true;
}

void trial(int cnt){
  if(cnt==n){
    for(int i = 0; i < n; i++){
      cout << ans[i] << " ";
    }
    exit(0);
  }
  
  for(int i = -10; i <= 10; i++){
    ans[cnt] = i;
    if(check(cnt)) trial(cnt+1);
  }
}


int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      cin >> map[i][j];
    }
  }
  trial(0);
}