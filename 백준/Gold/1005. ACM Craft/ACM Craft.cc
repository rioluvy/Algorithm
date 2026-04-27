#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t;    cin >> t;
    while(t--){
      int n,k,x,y;
      cin >> n >> k;
      int time[1001];
      for(int i=1;i<n+1;i++){
        cin >> time[i];
      }
      vector<int> adj[1001] ;
      queue<int> q;
      int check[1001] = {0,};
      int dur_time[1001]={0,};

      for(int i=0;i<k;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        check[y]++;
      }

      for(int i=1;i<n+1;i++){
        if(!check[i]) {
          q.push(i);
          dur_time[i] = time[i];
        }
      }

      int tar;
      cin >> tar;
      while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++){
          int next_node = adj[now][i];
          dur_time[next_node] = max(dur_time[next_node],dur_time[now]+time[next_node]);
            
          check[next_node]--;
          if(!check[next_node]) q.push(next_node);
        }
      }
      cout << dur_time[tar] << endl;

    }

}