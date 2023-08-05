#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <sstream>
#include <cmath>
#define endl "\n"

using namespace std;
int BFS(char map[][51], char name[],int startX, int startY);
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string act[4] = {"D","R","U","L"};
string action = "";
int visited[50][50] = {0,};
int c = 0;
int n, m, s, startX = 0, startY = 0;
pair<int,int> lastPos;
bool escape = false;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  char map[50][51];
  cin >> n >> m >> s;
  char name[1001];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> map[i][j];
    }
  }
  cin >> name;

  while(true){
    int check = BFS(map,name,startX,startY);
    if(check == 1) {
      c++;
      continue;
    }
    break;
  }
  escape = true;
  memset(visited, 0, sizeof(visited));
  BFS(map,name,startX,startY);
  cout << c << " " << action.length() << endl;
  cout << action << endl;

}

int BFS(char map[][51], char name[],int start_x, int start_y){
  int x, y, tmpx, tmpy;
  int length = 0;
  string tmpAction = "";
  string saveAction = "";
  queue<pair<int,pair<int,string>>> word;
  word.push({start_x,{start_y,""}});
  visited[start_x][start_y] = 1;
  while(!word.empty()){
    pair<int,pair<int,string>> location = word.front();
    x = location.first; y = location.second.first;
    word.pop();
    if(escape == false){
      if(map[x][y] == name[length]){ 
        map[x][y] = '\0';
        tmpAction += (location.second.second+"P");
        length++;
        memset(visited, 0, sizeof(visited));
        while(!word.empty()) {
          word.pop();
        }
        location.second.second = "";
        visited[x][y] = 1;
        saveAction += tmpAction;
        tmpAction = "";
        if(length == s){
          action += saveAction;
          startX = x;
          startY = y;
          return 1;
        }
      }
    }
    
    for(int i = 0; i < 4; i++){
      tmpx = x + dx[i];
      tmpy = y + dy[i];
      if(tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m){
        if(visited[tmpx][tmpy] != 1){
          if(escape && tmpx == n-1 && tmpy == m-1){
            action += (location.second.second + act[i]);
            return 0;
          }
          visited[tmpx][tmpy] = 1;
          word.push({tmpx,{tmpy,location.second.second + act[i]}});
        }
      }
    }
  }
  return 0;
}