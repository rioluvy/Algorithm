#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

int n, m, u, v, table[100001], parent[100001];

int find(int u){
  if(u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

void link(int u, int v){
  u = find(u);
  v = find(v);
  if(u==v) return;

  if(u < v) parent[v] = u;
  else parent[u] = v;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    link(u,v);
  }
  for(int i = 1; i <= n; i++) cin >> table[i];

  int start = find(table[1]);
  int cnt = 0;
  for(int i = 2; i <= n; i++){
    if(find(table[i]) != start) cnt++;
    start = find(table[i]);
  }
  cout << cnt;
}