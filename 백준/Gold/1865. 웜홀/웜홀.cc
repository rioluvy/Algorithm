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
int TC, N, M, W, S, E, T;
int MAX = 10000000;
bool travel(vector<pair<pair<int,int>,int>>& adj);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> TC;
  while(TC--){
    string ans = "NO";
    cin >> N >> M >> W;
    vector<pair<pair<int,int>,int>> adj;
    for(int i = 0; i < M; i++){
      cin >> S >> E >> T;
      adj.push_back({{S,E},T});
      adj.push_back({{E,S},T});
    }
    for(int i = 0; i < W; i++){
      cin >> S >> E >> T;
      adj.push_back({{S,E},-T});
    }
    if(travel(adj)) ans = "YES";
    cout << ans << endl;
  }
}

bool travel(vector<pair<pair<int,int>,int>>& arr){
  int cur, next, cost;
  vector<int> dist(N+1, MAX);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < arr.size(); j++){
      cur = arr[j].first.first;
      next = arr[j].first.second;
      cost = arr[j].second;
      if (dist[cur] + cost < dist[next]) {
        dist[next] = dist[cur] + cost;
        if (i == N-1) return true;
      }
    }
  }
  return false;
}