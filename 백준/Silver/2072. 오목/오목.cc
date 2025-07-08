#include<iostream>
using namespace std;

int board[20][20];
int dx[4] = {1,0,1,-1};
int dy[4] = {0,1,1,1};

int count(int x, int y, int dx, int dy, int color){
  if(x < 1 || y < 1 || x > 19 || y > 19) return 0;
  if(board[x][y] != color) return 0;
  return 1 + count(x+dx, y+dy, dx, dy, color);
}

bool isWin(int x, int y, int color){
  for(int i = 0; i < 4; i++){
    int cnt = 1;
    cnt += count(x + dx[i], y + dy[i], dx[i], dy[i], color);
    cnt += count(x - dx[i], y - dy[i], -dx[i], -dy[i], color);
    if(cnt == 5) return true;
  }
  return false;
}

int main(){
  int n, x, y;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    board[x][y] = i%2+1; // 2흑 1백
    if(isWin(x,y,i%2+1)) {
      cout << i+1;
      return 0;
    }
  }
  cout << -1;
}