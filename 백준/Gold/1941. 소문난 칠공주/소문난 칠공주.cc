#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pii pair<int,int>
using namespace std;

int map[5][5], tmp[25], visited[25], cnt, ans;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,};

int isAdj(vector<int>& pick){
  int vis[5][5];
  memset(vis,0,sizeof(vis));
  queue<pii> q;
  int start = pick[0];
  q.push({start/5,start%5});
  vis[start/5][start%5] = true;
  int adj = 1;
  while(!q.empty()){
    pii tmp = q.front();
    q.pop();
    int x = tmp.first;
    int y = tmp.second;
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
      int idx = nx*5+ny;
      if(visited[idx] && !vis[nx][ny]){
        q.push({nx,ny});
        vis[nx][ny] = 1;
        adj++;
      }
    }
  }
  return adj==7;
}

int trial(int idx, int cnt, int s){
  if(cnt == 7) {
    if(s >= 4){
      vector<int> pick;
      for(int i = 0; i < 25; i++){
        if(visited[i]) pick.push_back(i);
      }
      if(isAdj(pick)) ans++;
    }
    return 0;
  }

  for(int i = idx; i < 25; i++){
    visited[i] = true;
    trial(i+1, cnt+1, s + map[i/5][i%5]);
    visited[i] = false;
  }
  return ans;
}

int main(){
  char c;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> c;
      map[i][j] = (c=='S' ? 1 : 0);
    }
  }
  cout << trial(0,0,0);
}