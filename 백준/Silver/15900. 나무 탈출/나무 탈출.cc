#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int main() {
	int n,a,b;
	cin >> n;
	vector<vector<int>> info(n+1);
	for(int i = 0; i < n-1;i++){
		cin >> a >> b;
		info[a].push_back(b);
		info[b].push_back(a);
	}
	vector<int> leaf;
	vector<bool> visited(n+1,false);
	vector<ll> dis(n+1,0);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		int cnt = 0;
		for(auto v : info[node]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
				dis[v] = dis[node]+1;
				cnt++;
			}
			
		}
		if(cnt == 0) leaf.push_back(node);
	}
	ll ans = 0;
	for(auto v : leaf){
		ans += dis[v];
	}
	if(ans%2==1) cout << "Yes";
	else cout << "No";
	
}