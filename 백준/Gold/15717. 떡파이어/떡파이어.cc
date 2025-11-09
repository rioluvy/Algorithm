#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
#define mod 1000000007
using namespace std;

ll n;

ll power(ll a,ll b){
  if(b == 0) return 1;
  ll half = power(a,b/2);
  half = (half*half)%mod;
  if(b%2==1) return (half*a)%mod;
  return half;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  if(n==0) cout << 1;
  else cout << power(2,n-1);
}