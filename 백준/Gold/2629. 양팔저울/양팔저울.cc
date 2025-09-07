#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main(){
  int n, t, tc;
  cin >> n;
  vector<int> w(n,0);
  vector<bitset<15001>> cache(n+1);
  for(auto& v : w) cin >> v;

  cache[0][0] = 1;
  for(int i = 1; i <= n; i++){
    cache[i] |= (cache[i-1]);
    cache[i] |= (cache[i] << w[i-1]);
    for(int j = 0; j <= 15000; j++){
      if(cache[i-1][j]){
        cache[i][abs(j-w[i-1])] = 1;
      }
    }
  }
  cin >> t;
  while(t--){
    cin >> tc;
    if(tc > 15000) cout << 'N' << " ";
    else cout << (cache[n][tc] ? "Y ": "N ");
  }
}