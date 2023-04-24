#include <iostream>

using namespace std;
int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  long long pinary[91];
  pinary[1] = 1;
  pinary[2] = 1;
  for(int i = 3; i <= n; i++){
    pinary[i] = pinary[i-1] + pinary[i-2];
  }
  cout << pinary[n];

  return 0;
}