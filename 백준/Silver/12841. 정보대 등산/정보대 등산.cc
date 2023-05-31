#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"
#define ll long long

using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, tmp, idx, sum = 0;
  cin >> n;
  ll* cross = new ll[n+1];
  ll* left = new ll[n];
  left[0] = 0;
  ll* right = new ll[n];
  right[0] = 0;
  for(ll i = 1; i < n+1; i++){
    cin >> cross[i];
  }
  for(ll i = 1; i < n; i++){
    cin >> tmp;
    sum += tmp;
    left[i] = sum;
  }

  sum = 0;
  for(ll i = 1; i < n; i++){
    cin >> tmp;
    sum += tmp;
    right[i] = sum;
  }

  ll min = 9223372036854775807;
  idx = 1;
  for(ll i = 1; i < n+1; i++){
    tmp = cross[i] + left[i-1] + right[n-1] - right[i-1];
    if (tmp < min){
      min = tmp;
      idx = i;
    }
  }
  cout << idx << ' ' << min;

  return 0;
}