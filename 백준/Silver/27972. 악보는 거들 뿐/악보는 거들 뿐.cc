#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main(){
  int n, up = 0, down = 0, ans = 0;
  cin >> n;
  int *sheet = new int[n];
  for(int i = 0; i < n; i++){
    cin >> sheet[i];
  }

  for(int i = 1; i < n; i++){
    if(sheet[i] > sheet[i-1]){
      down = 0; up++;
      ans = max(ans,up);
    }else if(sheet[i] < sheet[i-1]){
      down++;
      up = 0;
      ans = max(ans,down);
    }
  }
  cout << ans+1;
}