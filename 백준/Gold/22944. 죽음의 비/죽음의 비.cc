#include <iostream>
#include <queue>
using namespace std;

struct State{
  int x,y,h,d,cnt;
};

int n, h, d, start;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char map[501][501];
int visited[501][501];
queue<State> q;

void trial(){
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    int x = cur.x;
    int y = cur.y;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(map[nx][ny] == 'E'){
        cout << cur.cnt+1;
        return;
      }
      int nh,nd;
      nd = cur.d;
      nh = cur.h;

      if(map[nx][ny] == 'U')
        nd = d;

      if(nd > 0) nd--;
      else nh--;

      if(nh == 0 || (visited[nx][ny] >= nh+nd)) continue;
      visited[nx][ny] = nh+nd;

      q.push({nx,ny,nh,nd,cur.cnt+1});
    }
  }
  cout << -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> h >> d;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> map[i][j];
      if(map[i][j] == 'S') {
        q.push({i,j,h,0,0});
        visited[i][j] = h;
      }
    }
  }
  trial();
  return 0;
}