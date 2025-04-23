#include <iostream>
#include <cmath>
using namespace std;

int star[5][5] = {
  {0,0,1,0,0},
  {0,0,1,0,0},
  {1,1,1,1,1},
  {0,1,1,1,0},
  {0,1,0,1,0}
};

bool isStar(int i, int j, int step){
  int ni = (i/step) % 5;
  int nj = (j/step) % 5;

  if(step == 1) 
    return star[nj][ni];

  if(star[nj][ni]) 
    return isStar(i,j,step/5);

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cout.tie(0);
  double n;
  cin >> n;
  if(n == 0) {
    cout << "*";
    return 0;
  }
  n = pow(5,n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << (isStar(j,i,n/5) ? "*" : " ");
    }
    cout << "\n";
  }
}