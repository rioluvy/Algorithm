#include<iostream>
using namespace std;

int n, a, tmp, ans;

int main(){
  cin >> n >> tmp;
  int last = tmp;
  for(int i = 1; i < n; i++){
    cin >> a;
    if(tmp >= a) ans++;
    tmp = a;
  }
  if(tmp >= last) ans++;
  cout << ans;
}