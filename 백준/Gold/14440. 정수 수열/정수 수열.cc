#include<iostream>
#include<iomanip>
#define mod 100
using namespace std;

int x, y, a0, a1, n;

struct Matrix{
  int a[2][2];
};

Matrix mmul(Matrix a, Matrix b){
  Matrix c;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      c.a[i][j] = 0;
      for(int k = 0; k < 2; k++){
        c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j]) % mod;
      }
    }
  }
  return c;
}

Matrix mPow(Matrix base, int exp){
  Matrix res = {{{1,0},{0,1}}};
  while(exp > 0){
    if(exp & 1) res = mmul(base,res);
    base = mmul(base,base);
    exp >>= 1;
  }
  return res;
}

int main(){
  cin >> x >> y >> a0 >> a1 >> n;
  if(n==0) {cout << setw(2) << setfill('0') << a0; return 0;}
  if(n==1) {cout << setw(2) << setfill('0') << a1; return 0;}

  Matrix m = {{{x,y},{1,0}}};
  Matrix mn = mPow(m,n-1);

  int ans = (mn.a[0][0] * a1 + mn.a[0][1] * a0) % mod;
  cout << setw(2) << setfill('0') << ans;
}