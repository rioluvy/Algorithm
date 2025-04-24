#include <iostream>
#include <string>
using namespace std;

bool star[3072][6144];

void drawStar(int i, int j, int step){
  if(step == 3){
    star[i][j] = true;
    star[i+1][j-1] = star[i+1][j+1] = true;
    for(int k = 0; k < 5; k++){
      star[i+2][j-2+k] = true;
    }
    return;
  }
  int tmp = step/2;
  drawStar(i,j,tmp);
  drawStar(i+tmp,j-tmp,tmp);
  drawStar(i+tmp,j+tmp,tmp);
}

int main(){
  ios_base::sync_with_stdio(0); cout.tie(0);
  int n, h, w;
  cin >> n;
  h = n, w = h*2-1;

  drawStar(0,w/2,h);

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << (star[i][j] ? '*':' ');
    }
    cout << '\n';
  }
}