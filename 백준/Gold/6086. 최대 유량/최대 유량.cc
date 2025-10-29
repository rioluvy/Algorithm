#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 700
using namespace std;

char u, v;
int n, c, flow[MAX][MAX], capa[MAX][MAX], visited[MAX], res;
vector<int> arr[MAX];

int max_flow(int start,int end){
  while(1){
    fill(visited,visited+MAX,-1);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      u = q.front();
      q.pop();
      for(int i = 0; i < arr[u].size(); i++){
        v = arr[u][i];
        if(visited[v] == -1 && capa[u][v] - flow[u][v] > 0){
          visited[v] = u;
          q.push(v);
          if(v == end) break;
        }
      }
    }
    if(visited[end] == -1) break;
    int f = 2147483647;
    for(int v = end; v != start; v = visited[v]){
      int p = visited[v];
      f = min(f, capa[p][v] - flow[p][v]);
    }

    for(int v = end; v != start; v = visited[v]){
      int p = visited[v];
      flow[p][v] += f;
      flow[v][p] -= f;
    }
    res += f;
  }
  return res;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> u >> v >> c;
    if('A' <= u && u <= 'Z') u = u-'A';
    else u = u -'a' + 26;
    if('A' <= v && v <= 'Z') v = v-'A';
    else v = v - 'a' + 26;

    capa[u][v] += c;
    capa[v][u] += c;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }

  cout << max_flow(0,'Z'-'A');
}