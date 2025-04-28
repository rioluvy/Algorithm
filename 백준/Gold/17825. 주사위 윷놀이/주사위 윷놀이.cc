#include <iostream>
using namespace std;

struct Node {
  int value, next;
};

int dice[10], pos[4], visited[33], point, ans = -1;
Node node[33];

void setGraph(){
  //빨간색 정방향
  for(int i = 0; i < 21; i++){
    node[i].value = i*2;
    node[i].next = i+1;
  }
  //파란색 방향 설정
  node[5].next = 22;
  node[10].next = 25;
  node[15].next = 27;
  //10road
  node[22].next = 23;
  node[23].next = 24;
  node[24].next = 30;
  node[22].value = 13;
  node[23].value = 16;
  node[24].value = 19;
  //20road
  node[25].next = 26;
  node[26].next = 30;
  node[25].value = 22;
  node[26].value = 24;
  //30road
  node[27].next = 28;
  node[28].next = 29;
  node[29].next = 30;
  node[27].value = 28;
  node[28].value = 27;
  node[29].value = 26;
  //final
  node[30].next = 31;
  node[31].next = 32;
  node[32].next = 20;
  node[30].value = 25;
  node[31].value = 30;
  node[32].value = 35;

  node[21].value = 0;
  node[21].next = -1;
}

bool checkPos(int cur, int cnt){
  int tmpNode;
  if((cur < 5) || (cur > 5 && cur < 10) || (cur > 10 && cur < 15)){
    tmpNode = cur + cnt;
  }
  else{
    tmpNode = cur;
    for(int i = 0; i < cnt; i++){
      tmpNode = node[tmpNode].next;
      if(tmpNode == 21) return true;
    }
  }

  for(int i = 0; i < 4; i++){
    if(pos[i] == tmpNode) return false;
  }
  return true;
}

void trial(int step){
  if(step==10){
    ans = max(ans,point);
    return;
  }

  for(int i = 0; i < 4; i++){
    int savePos = pos[i];
    int nNode = pos[i];
    if(pos[i] != 21 && checkPos(nNode,dice[step])){
      if((pos[i] < 5) || (pos[i] > 5 && pos[i] < 10) || (pos[i] > 10 && pos[i] < 15)){
        nNode = pos[i] + dice[step];
      }
      else{
        for(int j = 0; j < dice[step]; j++){
          nNode = node[nNode].next;
          if(nNode == 21) break;
        }
      }
      pos[i] = nNode;
      point += node[nNode].value;
      trial(step+1);
      pos[i] = savePos;
      point -= node[nNode].value;
    }
  }
}

int main(){
  for(auto &i:dice) cin >> i;
  setGraph();
  trial(0);
  cout << ans;
}