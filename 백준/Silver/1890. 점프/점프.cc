#include<iostream>
#include<cstring>
#define lint long long
using namespace std;

lint n, board[100][100], cache[100][100], ans;

lint trial(int x, int y){
  if(x >= n || y >= n) return 0;
  if(x == n-1 && y == n-1) return 1;
  if(!board[x][y]) return 0;

  lint& ret = cache[x][y];
  if(ret != -1) return ret;
  ret = 0;
  ret += (trial(x+board[x][y],y) + trial(x,y+board[x][y]));
  return ret;
}

int main(){
  cin >> n;
  memset(cache,-1,sizeof(board));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
  cout << trial(0,0);
}