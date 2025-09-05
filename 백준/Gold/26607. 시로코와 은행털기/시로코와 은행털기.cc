#include<iostream>
#include<vector>
#include<bitset>
#include<climits>
#include<cmath>
using namespace std;

int main(){
  int n,k,x;
  cin >> n >> k >> x;
  int a,b,arr[81];
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    arr[i] = a;
  }

  vector<bitset<16001>> cache(k+1);
  cache[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = k-1; j >= 0; j--){
      cache[j+1] |= cache[j] << arr[i];
    }
  }

  int pivot = k*x/2;
  int diff = INT_MAX;
  int m = 0;
  for(int i = 1; i <= 16000; i++){
    if(cache[k][i]){
      int tmp = abs(pivot-i);
      if(tmp <= diff){
        diff = tmp;
        m = i;
      }
    }
  }
  cout << m*(k*x-m);
}