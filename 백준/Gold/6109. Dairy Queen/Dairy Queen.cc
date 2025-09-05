#include<iostream>
using namespace std;

int n, c, cache[301],coins[9];

int main(){
  cin >> n >> c;
  for(int i = 0; i < c; i++){
    cin >> coins[i];
  }
  cache[0] = 1;
  for(int i = 0; i < c; i++){
    for(int j = coins[i]; j <= n; j++){
      cache[j] += cache[j-coins[i]];
    }
  }
  cout << cache[n];
}