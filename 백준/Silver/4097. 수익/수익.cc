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

int n, cache[250001], profit[250001];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  while(cin >> n && n != 0){
    for(int i = 1; i <= n; i++){
      cin >> profit[i];
    }
    int ans = INT_MIN;
    int psum = 0;
    for(int i = 1; i <= n; i++){
      psum += profit[i];
      ans = max(ans,psum);
      if(psum < 0) psum = 0;
    }
    cout << ans << "\n";
  }
}