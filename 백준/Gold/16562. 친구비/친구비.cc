#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

int parent[10001];

int price[10001];

int find(int u){

    if(parent[u]==u) return u;

    return parent[u]=find(parent[u]);

}

void merge(int u,int v){

    u=find(u);

    v=find(v);

    if(u==v) return;

    if(price[u]>price[v]) parent[u]=v;

    else parent[v]=u;

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m,k,a,b,total=0;

    cin >>n>>m>>k;

    for(int i=1;i<n+1;i++){

      cin >> price[i];

      parent[i]=i;

    }

    for(int i=0;i<m;i++){

      cin >> a>>b;

      merge(a,b);

    }

    vector<int> tmp;

    for(int i=1;i<n+1;i++){

      if(find(tmp.begin(),tmp.end(),find(i))==tmp.end()){

        tmp.push_back(find(i));

        total+=price[find(i)];

      }

    }

    

    if(k<total) cout << "Oh no";

    else cout << total;

}