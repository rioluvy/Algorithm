#include <iostream>

#include <algorithm>

#define endl "\n"

using namespace std;

int parent[1000001];

int height[1000001];

int find(int u){

    if(u==parent[u]) return u;

    return parent[u] = find(parent[u]);

}

void merge(int u,int v){

    u = find(u);

    v = find(v);

    if(u==v) return;

    if(height[u]>height[v]) swap(u,v);

    parent[u] = v;

    if(height[u]==height[v]) height[v]++;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,check,a,b;

    cin >> n >> m;

    for(int i=0;i<n+1;i++){

      parent[i] = i;

      height[i] = 1;

    }

    for(int i=0;i<m;i++){

      cin >> check>>a>>b;

      if(!check) merge(a,b);

      else {

        if(find(a) == find(b)) cout << "YES"<<endl;

        else cout << "NO"<< endl;

      }

    }

}