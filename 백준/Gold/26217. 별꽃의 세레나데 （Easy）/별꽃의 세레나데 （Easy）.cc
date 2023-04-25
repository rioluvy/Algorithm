#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
double harmonic(double n){
  double sum = 0;
  for(double i = 1; i < n+1; i++){
    sum += 1/i;
  }
  return sum;
}

int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  double n, ans;
  cin >> n;
  ans = n * harmonic(n);
  cout << ans;
  return 0;
}