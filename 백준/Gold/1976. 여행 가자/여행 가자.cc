#include <iostream>

#include <algorithm>

#define endl "\n";

using namespace std;

int parent[201];

int find(int u){

    if(u==parent[u]) return u;

    return parent[u] = find(parent[u]);

}

void merge(int u,int v){

    u = find(u);

    v = find(v);

    if(u==v) return;

    if(u<v) parent[v]=u;

    else parent[u] = v;

    

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m,check;    cin >> n >>m;

    for(int i=1;i<n+1;i++){

      parent[i]=i;

    }

    

    for(int i=1;i<n+1;i++){

      for(int j=1;j<n+1;j++){

        cin >>check;

        if(check) merge(i,j);

      }

    }

    

    int seq;

    bool ans = true;

    int start;

    cin >> start;

    start = find(start);

    for(int i=1;i<m;i++) {

      cin>>seq;

      if(start!=find(seq)) ans=false;

    }

    

    if(ans) cout << "YES";

    else cout << "NO";

}