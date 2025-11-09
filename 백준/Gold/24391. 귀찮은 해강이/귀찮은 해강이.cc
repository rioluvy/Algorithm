#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
using namespace std;

int n, m, parent[100001], table[100001];

int find(int u){
  if(parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}

void link(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return;
  if(u < v) parent[v] = u;
  else parent[u] = v;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
  int u,v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    link(u,v);
  }

  for(int i = 1; i <= n; i++){
    cin >> table[i];
  }
  int start = find(table[1]);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(start != find(table[i])){
      ans++;
      start = find(table[i]);
    }
  }
  cout << ans;
}