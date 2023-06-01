#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"

using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,k,out;
  cin >> n >> k;
  queue<int> q;
  int visited[100001];
  memset(visited,0,sizeof(visited));
  q.push(n);
  visited[n] = 1;
  while (q.size() != 0){
    out = q.front();
    if(out == k) break;
    q.pop();

    if(out*2 <= 100000 && out*2 >= 0){
      if(visited[out*2] == 0 || visited[out*2] > visited[out]){
        q.push(out*2);
        visited[out*2] = visited[out];
      }
    } 
    if(out+1 <= 100000){
      if (visited[out+1] == 0 || visited[out+1] > visited[out]+1){
        q.push(out+1);
        visited[out+1] = visited[out] + 1;
      } 
    }
    if(out-1 >= 0){
      if(visited[out-1] == 0 || visited[out-1] > visited[out]+1){
        q.push(out-1);
        visited[out-1] = visited[out] + 1;
      } 
    }
  }
  std::cout << visited[out]-1;
}