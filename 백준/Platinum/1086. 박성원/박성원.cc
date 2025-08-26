#include<iostream>
#include<string>
#include<numeric>
#include<cstring>
#define lint long long
using namespace std;

int n,k, modNum[16], mod10[16];
lint dp[1<<15][101];
string s, num[16];

void prep() {
  for(int i = 0; i < n; i++){
    s = num[i];
    int m = 0;
    for(char c : s){
      m = (m*10+(c-'0')) % k;
    }
    modNum[i] = m;

    int l = s.size();
    int m10 = 1;
    for(int j = 0; j < l; j++){
      m10 = (m10*10) % k;
    }
    mod10[i] = m10;
  }
};

lint trial(int mask, int r){
  if(mask == (1<<n)-1) return r == 0;
  
  lint& ret = dp[mask][r];
  if(ret != -1) return ret;

  ret = 0;
  for(int i = 0; i < n; i++){
    if((mask & (1<<i))) continue;
    int nxt = (r*mod10[i] + modNum[i]) % k;
    ret += trial(mask|(1<<i),nxt);
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  cin >> k;
  prep();
  memset(dp,-1,sizeof(dp));
  
  lint ansCase = trial(0,0);
  lint totalCase = 1;
  for(int i = 1; i <= n; i++){
    totalCase *= i;
  }
  lint g = gcd(totalCase,ansCase);
  cout << ansCase/g << '/' << totalCase/g;
}