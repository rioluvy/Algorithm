#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

int parent[500001];

int ans=0;

int find(int u){

  if(parent[u]==u) return u;

  return parent[u]=find(parent[u]);

}

void merge(int u,int v,int i){

  u=find(u);

  v=find(v);

  if(u==v) {

    if(!ans){

      ans=i+1;

    }

    return;

  }

  else if(u>v) parent[u]=v;

  else parent[v]=u;

}

int main() {
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n, m, a, b;    cin >> n >>m;

    for(int i=1;i<n+1;i++){

      parent[i]=i;

    }

    for(int i=0;i<m;i++){

      cin >> a >> b;

      merge(a,b,i);

    }

    cout << ans;

}