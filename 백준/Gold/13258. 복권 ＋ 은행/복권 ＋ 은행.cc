#include<iostream>
using namespace std;

int main(){
  double n, j, c, psum = 0, ac[51];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ac[i];
    psum += ac[i];
  }
  cin >> j >> c;
  double tmp = j*c*ac[0]/psum;
  double ans = tmp + ac[0];
  cout.precision(15);
  cout << ans;
}