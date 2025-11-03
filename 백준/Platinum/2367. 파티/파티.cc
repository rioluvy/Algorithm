#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,k,d, weight[101], capacity[400][400], flow[400][400], visited[400], tmp, u, v, ans;
vector<int> info[400];

int max_flow(int start, int end){
  while(true){
    fill(visited,visited+400,-1);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      u = q.front();
      q.pop();
      for(int i = 0; i < info[u].size(); i++){
        v = info[u][i];
        if(visited[v] == -1 && capacity[u][v] - flow[u][v] > 0){
          visited[v] = u;
          q.push(v);
          if(v == end) break;
        }
      }
    }
    if(visited[end] == -1) break;
    int f = 2147483647;
    for(int v = end; v != start; v = visited[v]){
      u = visited[v];
      f = min(f,capacity[u][v] - flow[u][v]);
    }
    for(int v = end; v != start; v = visited[v]){
      u = visited[v];
      flow[u][v] += f;
      flow[v][u] -= f;
    }
    ans += f;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> d;
  for(int i = 1; i <= d; i++) cin >> weight[i];
  for(int i = 1; i <= n; i++){
    info[0].push_back(i);
    info[i].push_back(0);
    capacity[0][i] = k;
  }
  for(int i = 1; i <= n; i++){
    cin >> tmp;
    for(int j = 0; j < tmp; j++){
      int num;
      cin >> num;
      info[i].push_back(num+n);
      info[num+n].push_back(i);
      capacity[i][num+n] = 1;
    }
  }
  int idx = 1;
  for(int i = n+1; i <= n+d; i++){
    info[i].push_back(n+d+1);
    info[n+d+1].push_back(i);
    capacity[i][n+d+1] = weight[idx]; 
    idx++;
  }

  cout << max_flow(0,n+d+1);
}