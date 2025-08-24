#include<iostream>
#include<cstring>
#define lint long long
#define mod 1000000007
using namespace std;

lint t, l, cache[5001];

lint trial(int len){
  if(len == 0 || len == 2) return 1;

  lint& ret = cache[len];
  if(cache[len] != -1) return ret;
  ret = 0;

  for(int i = 0; i <= len-2; i+=2){
    ret += trial(i) * trial(len-i-2);
    ret %= mod;
  }
  return ret;
}

int main(){
  cin >> t;
  memset(cache,-1,sizeof(cache));
  while(t--){
    cin >> l;
    if(l & 1) {
      cout << 0 << "\n";
      continue;
    }
    cout << trial(l) << "\n";
  }
}