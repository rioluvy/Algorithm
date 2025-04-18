#include <iostream>
using namespace std;

int n, ans;
//ld: 좌상향, rd: 우상향
void trial(int row, int col, int ld, int rd){
  if(row == (1 << n) - 1){
    ans++;
    return;
  }

  //Queen이 가능한 곳이 1
  int avail = ~(col | ld | rd) & ((1 << n) - 1);

  while(avail){
    int bit = avail & -avail;
    avail ^= bit;
    //퀸을 놓으면 1
    trial(row|bit, col|bit, (ld | bit) >> 1, (rd | bit) << 1);
  }
}

int main(){
  cin >> n;
  trial(0,0,0,0);
  cout << ans;
}