#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int t, n, psum[100001];
bool prime[100002];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  for(int i = 2; i*i <= 100000; i++){
    if(!prime[i]){
      for(int j = i*i; j <= 100000; j+= i){
        prime[j] = true;
      }
    }
  }

  for(int i = 1; i <= 100000; i++){
    if(prime[i+1] || i%10 == 0) {
      psum[i] = psum[i-1];
      continue;
    }

    string s = to_string(i);
    int l = s.length()-1;
    bool flag = true;
    for(int j = 0; j < l; j++){
      string front = s.substr(0,j+1);
      string back = s.substr(j+1);
      int a = stoi(front);
      int b = stoi(back);
      if(prime[a*b+1]) {
        psum[i] = psum[i-1];
        flag = false;
        break;
      }
    }
    if(flag) psum[i] = psum[i-1]+1;
  }

  cin >> t;
  while(t--){
    cin >> n;
    cout << psum[n] << "\n";
  }
}