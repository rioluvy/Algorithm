#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<climits>
using namespace std;

int n, k, x, a, b;
int arr[81];

int main(){
  cin >> n >> k >> x;
  for(int i = 0; i < n; i++) cin >> arr[i] >> b;
  vector<bitset<16001>> cache(k+1);
  cache[0][0] = 1;
  
  for(int i = 0; i < n; i++){
    for(int j = k-1; j >= 0; j--){
      cache[j+1] |= (cache[j] << arr[i]);
    }
  }

  int pivot = k*x/2;
  int nearest = -1;
  int diff = INT_MAX;
  for(int i = 0; i < 16001; i++){
    if(cache[k][i]){
      int tmp = abs(i - pivot);
      if(tmp <= diff){
        diff = tmp;
        nearest = i;
      }
    }
  }

  int ans = nearest*(k*x-nearest);
  cout << ans;
}