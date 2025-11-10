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
#define mod 123456789
using namespace std;

int n, p[40001], cache[40001];
vector<int> coin;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  for(int i = 2; i <= 40000; i++){
    p[i] = i;
  }

  for(int i = 2; i <= 40000; i++){
    if(p[i] == 0) continue;
    for(int j = i*i; j <= 40000; j += i){
      p[j] = 0;
    }
  }

  for(int i = 2; i <= 40000; i++){
    if(p[i]!=0) coin.push_back(i);
  }

  cache[0] = 1;
  for(int i = 0; i < coin.size(); i++){
    for(int j = coin[i]; j <= n; j++){
      cache[j] += cache[j-coin[i]];
      cache[j] %= mod;
    }
  }
  cout << cache[n];
}