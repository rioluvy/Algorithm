#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;

bool visited[1000001];
int n, u, v;
vector<int> tree[1000001];

pii trial(int node){
  visited[node] = true;
  int early = 1;
  int notEarly = 0;

  for(auto child : tree[node]){
    if(!visited[child]) {
      auto [cEarly, cNotEarly] = trial(child);
      early += min(cEarly, cNotEarly);
      notEarly += cEarly;
    }
  }
  return {early,notEarly};
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  auto [ans1, ans2] = trial(1);
  cout << min(ans1, ans2);
}