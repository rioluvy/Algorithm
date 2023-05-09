#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main(){
  int n, c, ans = 0;
  cin >> n >> c;
  int* weight = new int[n];
  for(int i = 0; i < n; i++){
    cin >> weight[i];
  }
  sort(weight, weight+n);

  int x = 0, y = n-1;
  while(x < y){
    if(ans) break;

    for(int i = 0; i < n; i++){
      if(i == x || i == y){
        continue;
      }

      if(weight[x] == c || weight[y] == c || weight[i] == c) ans = 1;
      else if(weight[x] + weight[y] == c) ans = 1;
      else if(weight[x] + weight[y] + weight[i] == c) ans = 1;

    }
    if(weight[x] + weight[y] < c) x++;
    else if(weight[x] + weight[y] > c) y--;
  }
  cout << ans;

}