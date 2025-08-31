#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define pii pair<int,int>
using namespace std;

int n, cache[501][501];
vector<pii> v;

int trial(int x, int y){
  if(x==y) return 0;

  int& ret = cache[x][y];
  if(ret != -1) return ret;
  
  ret = INT_MAX;
  for(int i = x; i < y; i++){
    int tmp = trial(x,i) + trial(i+1,y) + v[x].first*v[i].second*v[y].second;
    ret = min(ret,tmp);
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int r,c;
    cin >> r >> c;
    v.push_back({r,c});
  }
  memset(cache,-1,sizeof(cache));

  cout << trial(0,n-1);
}