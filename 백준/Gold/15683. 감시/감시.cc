#include <iostream>
#include <vector>
#include <climits>
#define pii pair<int,int>
using namespace std;

int n,m,map[8][8],ans=INT_MAX;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pii> cctv;

void monitor(int x, int y, int d){
  d %= 4;
  while(true){
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] != 6){
      x = nx, y = ny;
      if(map[nx][ny] != 0) continue;
      map[nx][ny] = -1;
    }
    else break;
  }
}

int trial(int cur){
  if(cur==cctv.size()){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(!map[i][j]) cnt++;
      }
    }
    return ans = min(ans,cnt);
  }

  int x,y;
  x = cctv[cur].first;
  y = cctv[cur].second;
  int tmp[8][8];

  for(int d = 0; d < 4; d++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        tmp[i][j] = map[i][j];
      }
    }
    if(map[x][y] == 1){
      monitor(x,y,d);
    }
    else if(map[x][y] == 2){
      monitor(x,y,d);
      monitor(x,y,d+2);
    }
    else if(map[x][y] == 3){
      monitor(x,y,d);
      monitor(x,y,d+1);
    }
    else if(map[x][y] == 4){
      monitor(x,y,d);
      monitor(x,y,d+1);
      monitor(x,y,d+2);
    }
    else if(map[x][y] == 5){
      monitor(x,y,d);
      monitor(x,y,d+1);
      monitor(x,y,d+2);
      monitor(x,y,d+3);
    }
    trial(cur+1);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        map[i][j] = tmp[i][j];
      }
    }

  }
  return ans;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> map[i][j];
      if(map[i][j] != 0 && map[i][j] != 6) cctv.push_back({i,j});
    }
  }

  cout << trial(0);
}