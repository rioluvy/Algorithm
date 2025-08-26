#include<iostream>
#include<vector>
#include<numeric>
#define lint long long

using namespace std;

struct DSU {
  vector<int> parent;
  vector<lint> w;

  DSU(int N = 0){ init(N+1); }
  void init(int N){
    parent.resize(N);
    w.assign(N,0);
    iota(parent.begin(),parent.end(),0);
  }

  int find(int x){
    if(parent[x] == x) return x;
    int p = parent[x];
    int r = find(p);
    w[x] += w[p];
    return parent[x] = r;
  }

  void link(int a, int b, int weight){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;

    parent[pb] = pa;
    w[pb] = w[a] - w[b] + weight;
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int n, m, a, b, w;
  while(cin >> n >> m, n || m){
    DSU uf(n);
    for(int i = 0; i < m; i++){
      char c;
      cin >> c;
      if(c == '!') {
        cin >> a >> b >> w;
        uf.link(a,b,w);
      }
      else if(c == '?'){
        cin >> a >> b;
        if(uf.find(a) == uf.find(b)) cout << uf.w[b] - uf.w[a] << "\n";
        else cout << "UNKNOWN\n";
      }
    }
  }
}