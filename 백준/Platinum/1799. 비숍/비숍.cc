#include <iostream>
using namespace std;

int n, board[10][10], diag1[21], diag2[21], total;

int trial(int diag, int mem, int cnt, int kind){
  if(diag == 2*n-1) return cnt;

  int ret = cnt;
  int x = (diag < n) ? diag : n-1;
  int y = (diag < n) ? 0 : diag-n+1;

  while(x >= 0 && y < n){
    if((x+y)%2==kind && board[x][y]){
      //검사할 우하향 대각선 인덱스
      int idx = x-y+n-1;
      if(!(mem & (1<<idx))) ret = max(ret,trial(diag+1,mem|(1<<idx), cnt+1, kind));
    }
    x--,y++;
  }
  return max(ret,trial(diag+1,mem,cnt,kind));
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }

  total = trial(0,0,0,0);
  total += trial(0,0,0,1);
  cout << total;

}