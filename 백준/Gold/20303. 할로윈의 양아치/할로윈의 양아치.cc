#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
#define mod 1000000007
using namespace std;

int n, m, k, candy[30001], parent[30001], cache[30001], childNum[30001];

int find(int u){
  if(parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}

void link(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return;
  if(u > v) swap(u,v);
  parent[v] = u;
  candy[u] += candy[v];
  childNum[u] += childNum[v];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    cin >> candy[i];
    parent[i] = i;
    childNum[i] = 1;
  }

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    link(a,b);
  }
  
  vector<pii> arr;
  for(int i = 1; i <= n; i++){
    if(find(i) == i) arr.push_back({candy[i],childNum[i]});
  }

  for(int i = 0; i < arr.size(); i++){
    int val = arr[i].first;
    int w = arr[i].second;
    for(int j = k-1; j >= w; j--){
      cache[j] = max(cache[j],cache[j-w]+val);
    }
  }
  cout << cache[k-1];
}