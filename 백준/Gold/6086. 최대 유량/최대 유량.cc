#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cap[700][700], flow[700][700], visited[700], max_flow;
vector<int> arr[700];

int maxFlow(int start, int end) {
  while(true){
    fill(visited, visited+700, -1);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int i = 0; i < arr[u].size(); i++){
        int v = arr[u][i];
        if(visited[v] == -1 && cap[u][v] > flow[u][v]){
          q.push(v);
          visited[v] = u; // 어디서 왔는지 기록
          if(v == end) break;
        }
      }
    }
    if(visited[end] == -1) break;

    int f = 2147483647;
    for(int v = end; v != start; v = visited[v]){
      int p = visited[v];
      f = min(f,cap[p][v] - flow[p][v]);
    }
    for(int v = end; v != start; v = visited[v]){
      int p = visited[v];
      flow[p][v] += f;
      flow[v][p] -= f;
    }
    max_flow += f;
  }
  return max_flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  char u,v;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> u >> v >> c;
    if('A' <= u && u <= 'Z') u = u-'A';
    else u = u - 'a' + 26;

    if('A' <= v && v <= 'Z') v = v-'A';
    else v = v - 'a' + 26;

    cap[u][v] += c;
    cap[v][u] += c;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }
  cout << maxFlow(0,'Z'-'A');
}