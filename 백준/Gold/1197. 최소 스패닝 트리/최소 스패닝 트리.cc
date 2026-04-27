#include <iostream>

#include <algorithm>

#include <vector>

#include <tuple>

#define endl "\n"

using namespace std;

int parent[10001];

int find(int u){

    if(parent[u]==u) return u;

    return parent[u]=find(parent[u]);

}

void merge(int u,int v){

    u=find(u);

    v=find(v);

    if(u==v) return;

    if(u>v) parent[u]=v;

    else parent[v]=u;

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int v,e,a,b,c,cnt=0;    cin>>v>>e;

    vector<tuple<int,int,int>> info;

    for(int i=0;i<e;i++){

      cin>>a>>b>>c;

      info.push_back(make_tuple(c,a,b));

    }

    sort(info.begin(),info.end());

    for(int i=1;i<v+1;i++){

      parent[i]=i;

    }

    int ans=0;

    int i=0;

    while(cnt!=v-1){

      c=get<0>(info[i]);

      a=get<1>(info[i]);

      b=get<2>(info[i]);

     

      if(find(a)!=find(b)){

        merge(a,b);

        ans+=c;

        cnt++;

      }

      i++;

    }

    cout << ans;

}