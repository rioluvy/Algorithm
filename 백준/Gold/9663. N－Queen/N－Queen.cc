#include <iostream>
using namespace std;

int n, ans, col[16], dia1[31], dia2[31];

bool check(int r, int c){
  if(col[c] || dia1[r+c] || dia2[r-c+n] ) return false;
  return true;
}

int trial(int cur){
  if(cur == n+1) {
    return ans++;
  }
  for(int c = 1; c <= n; c++){
    if(check(cur, c)){
      col[c] = dia1[cur+c] = dia2[cur-c+n] = 1;
      trial(cur+1);
      col[c] = dia1[cur+c] = dia2[cur-c+n] = 0;
    }
  }
  return ans;
}

int main(){
  cin >> n;
  cout << trial(1);
}