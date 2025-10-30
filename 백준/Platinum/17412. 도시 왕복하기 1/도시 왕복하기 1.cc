#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, p, u, v, maxCap[401][401], visited[401], flow[401][401];
vector<int> info[401];

int maxFlow(int start, int end){
  int cnt = 0;
  while(1){
    fill(visited,visited+401,-1);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      u = q.front();
      q.pop();
      for(int i = 0; i < info[u].size(); i++){
        v = info[u][i];
        if(visited[v] == -1 && maxCap[u][v] - flow[u][v] > 0){
          q.push(v);
          visited[v] = u;
          if(v == end) break;
        }
      }
    }
    if(visited[end] == -1) break;

    int min_flow = 2147183647;
    for(int v = end; v != start; v = visited[v]){
      int parent = visited[v];
      min_flow = min(min_flow, maxCap[parent][v]-flow[parent][v]);
    }
    for(int v = end; v != start; v = visited[v]){
      int parent = visited[v];
      flow[parent][v] += min_flow;
      flow[v][parent] -= min_flow;
    }
    cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for(int i = 0; i < p; i++){
    cin >> u >> v;
    info[u].push_back(v);
    info[v].push_back(u);
    maxCap[u][v] = 1;
  }
  cout << maxFlow(1,2);
}