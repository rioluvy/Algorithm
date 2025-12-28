#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n, a[100001], q, tmp;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> tmp;
    a[tmp]++;
  }

  for(int i = 1; i <= 100000; i++){
    if(a[i] == 0) continue;
    for(int j = i*2; j <= 100000; j+=i){
      a[j] += a[i];
    }
  }

  cin >> q;
  while(q--){
    cin >> tmp;
    cout << a[tmp] << " ";
  }
}