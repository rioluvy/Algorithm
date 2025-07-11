#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#define pii pair<int,int>
using namespace std;

string s;
vector<pii> v;
bool visited[12][6];
char field[12][7];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans, flag = 1;

void down(){
  for(int i = 0; i < 6; i++){
    vector<char> tmp;
    for(int j = 11; j >= 0; j--){
      if(field[j][i] != '.'){
        tmp.push_back(field[j][i]);
      }
    }
    int sz = 11;
    for(char c : tmp) field[sz--][i] = c;
    while(sz >= 0) field[sz--][i] = '.';
  }
}

void boom(){
  for(int i = 0; i < v.size(); i++){
    auto [x,y] = v[i];
    field[x][y] = '.';
  }

}

int count(int i, int j, char p){
  int cnt = 1;
  queue<pii> q;
  v.push_back({i,j});
  q.push({i,j});
  visited[i][j] = true;
  while(!q.empty()){
    auto [x,y] = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx > 11 || ny > 5) continue;
      if(field[nx][ny] != p) continue;
      if(!visited[nx][ny]){
        q.push({nx,ny});
        visited[nx][ny] = true;
        v.push_back({nx,ny});
        cnt++;
      }
    }
  }
  memset(visited,0,sizeof(visited));
  return (cnt >= 4) ? 1 : 0;
}

int main(){
  for(int i = 0; i < 12; i++){
    cin >> s;
    for(int j = 0; j < 6; j++){
      field[i][j] = s[j];
    }
  }

  while(flag){
    flag = 0;
    for(int i = 0; i < 12; i++){
      for(int j = 0; j < 6; j++){
        if(field[i][j] == '.') continue;
        if(visited[i][j]) continue;
        v.clear();
        char pivot = field[i][j];
        if(count(i,j,pivot) == 1){
          boom();
          flag = 1;
        }
      }
    }
    if(flag){
      down();
      ans++;
    }

  }
  cout << ans;
}