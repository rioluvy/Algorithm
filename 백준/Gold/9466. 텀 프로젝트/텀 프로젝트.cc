#include<iostream>
#include<vector>
using namespace std;

int t, n, cnt;
vector<int> info;
vector<int> state;

void trial(int node){
  state[node] = 1;
  int nxt = info[node];
  if(state[nxt] == 0) trial(nxt);
  if(state[nxt] == 1){
    int start = nxt;
    while(true){
      cnt++;
      nxt = info[nxt];
      if(start == nxt) break;
    }
  }
  state[node] = 2;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    info.resize(n+1);
    state.assign(n+1,0);
    for(int i = 1; i <= n; i++){
      cin >> info[i];
    }
    for(int i = 1; i <= n; i++) {
      if(state[i] != 2) trial(i);
    }
    cout << n-cnt << "\n";
    cnt = 0;
  }
}