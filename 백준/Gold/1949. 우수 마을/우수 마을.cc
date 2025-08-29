#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;

bool visited[10001];
int n, u, v;
vector<int> tree[10001];
vector<int> population;

pii trial(int node){
  visited[node] = true;
  int selected = population[node];
  int nonSelected = 0;

  for(auto child : tree[node]){
    if(!visited[child]){
      auto [a, b] = trial(child);
      selected += b;
      nonSelected += max(a,b);
    }
  }
  return {selected,nonSelected};
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  population.resize(n+1);
  for(int i = 1; i <= n; i++){
    cin >> population[i];
  }
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  auto [ans1, ans2] = trial(1);
  cout << max(ans1, ans2);
}