#include<iostream>
using namespace std;

int candy[51];

int main(){
  int n, tmp, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    candy[tmp]++;
  }
  ans += candy[1];
  int prev = candy[1];
  for(int i = 2; i < 51; i++){
    if(!candy[i]) break;
    prev *= candy[i];
    ans += prev;
  }
  cout << ans;
}