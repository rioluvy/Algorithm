#include<iostream>
using namespace std;

int n, k, prime[100001], ans = 0;
int main(){
  cin >> n >> k;
  for(int i = 2; i<= n; i++){
    if(!prime[i]){
      for(int j = i; j <=n; j+=i){
        prime[j] = max(prime[j],i);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(prime[i] <= k) ans++;
  }
  cout << ans;
}