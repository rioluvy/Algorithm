#include <iostream>
using namespace std;

int n, m, sum, psum, arr[10001][101];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    sum = 0;
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
      sum += arr[i][j];
    }

    for(int j = 0; j < n; j++){
      if(psum == sum/2){
        for(int k = 0; k < j; k++) cout << 1 << " ";
        for(int k = j; k < n; k++) cout << -1 << " ";
        break;
      }
      else psum += arr[i][j];
    }
    psum = 0;
    cout << "\n";
  }
}