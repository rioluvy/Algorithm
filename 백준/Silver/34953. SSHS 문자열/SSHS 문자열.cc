#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  string s;
  for(int i = 1; i <= n; i++){
    if(i%3==0) s += 'H';
    else s += 'S';
  }
  cout << s;
}