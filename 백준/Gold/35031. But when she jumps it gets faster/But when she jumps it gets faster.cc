#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

ll n, l, k, p[1000001], psum[1000001];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> l >> k;
  for(int i = 0; i < k; i++){
    int tmp;
    cin >> tmp;
    p[tmp] = 1;
  }
  for(int i = 1; i <= l; i++)
    psum[i] = psum[i-1] + p[i];

  ll total = n * l;
  ll cnt = 0;
  ll f = 0;
  while(cnt < total){    
    ll q = cnt / l;
    ll r = cnt % l;
    ll jumpCnt = q*k + psum[r];
    ll speed = 1+jumpCnt;

    cnt += speed;
    f++;
  }
  cout << f;
}