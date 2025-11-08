#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
using namespace std;

int n, safe, ans, map[101][101], visited[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void trial(int i, int j, int ck){
  queue<pii> q;
  q.push({i,j});
  visited[i][j] = ck+1;
  while(!q.empty()){
    auto [x,y] = q.front();
    q.pop();
    for(int d = 0; d < 4; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(0 > nx || nx >= n || ny < 0 || ny >= n) continue;
      if(visited[nx][ny] == ck){
        visited[nx][ny] = ck+1;
        q.push({nx,ny});
      }
    }
  }
}

void rain(int h){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] <= h) visited[i][j] = -1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> map[i][j];
    }
  }

  for(int h = 0; h <= 100; h++){
    safe = 0;
    rain(h);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(visited[i][j] == h) {
          trial(i,j,h);
          safe++;
        }
      }
    }
    ans = max(safe,ans);
  }
  cout << ans;
}