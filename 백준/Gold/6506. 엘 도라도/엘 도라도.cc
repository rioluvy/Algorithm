#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
using namespace std;

int n, k, arr[101];
ll cache[101][101];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  while(cin >> n >> k && n != 0 && k != 0){
    memset(cache,0,sizeof(cache));
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      cache[i][1] = 1;
    } 
    for(int l = 2; l <= k; l++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
          if(arr[i] > arr[j]){
            cache[i][l] += cache[j][l-1];
          }
        }
      }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
      ans += cache[i][k];
    }
    cout << ans << "\n";
  }
}