#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define endl "\n"

using namespace std;
void BFS(int e, vector<vector<int>> &com, bool* visited,int* ans);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  bool* visited = new bool[n+1];
  memset(visited,false,sizeof(visited));
  int* ans = new int[n+1];
  vector<vector<int>> com(n+1,vector<int>());

  for(int i = 0; i < m; i++){
    cin >> a >> b;
    com[b].push_back(a);
  }

  for(int i = 1; i < n+1 ; i++){
    BFS(i, com, visited, ans);
    fill_n(visited, n+1, false);
  }

  int max_val = *max_element(ans+1, ans + n+1);
  for(int i = 1; i < n+1; i++){
    if(ans[i] == max_val) cout << i << ' ';
  }
}

void BFS(int e, vector<vector<int>> &com, bool* visited,int* ans){
  queue<int> q;
  int cnt = 1;
  q.push(e);
  visited[e] = true;
  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    for(int i : com[tmp]) {
      if(!visited[i]){
        visited[i] = true;
        q.push(i);
        cnt++;
      }
    }
  }
  ans[e] = cnt;
}