#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <tuple>
using namespace std;
int parent[100001];
int find(int u){
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(u<v) parent[v] = u;
	else parent[u] = v;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
	int n,a,b,c,diff_x,diff_y,diff_z;
	vector<pair<int,int>> x;
	vector<pair<int,int>> y;
	vector<pair<int,int>> z;
	vector<tuple<int,int,int>> cost;
	cin >> n;
	for(int i = 1; i<n+1; i++){
		parent[i] = i;
		cin >> a >> b >> c;
		x.push_back({a,i});
		y.push_back({b,i});
		z.push_back({c,i});
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(z.begin(),z.end());
	for(int i = 0; i<n-1; i++){
		diff_x = abs(x[i].first - x[i+1].first);
		cost.push_back({diff_x,x[i].second,x[i+1].second});
		diff_y = abs(y[i].first - y[i+1].first);
		cost.push_back({diff_y,y[i].second,y[i+1].second});
		diff_z = abs(z[i].first - z[i+1].first);
		cost.push_back({diff_z,z[i].second,z[i+1].second});
	}
	sort(cost.begin(),cost.end());
	int ans=0,cnt=0,i=0;
	while(cnt!=n-1){
		if(find(get<1>(cost[i])) != find(get<2>(cost[i]))){
			merge(get<1>(cost[i]),get<2>(cost[i]));
				cnt++;
				ans += get<0>(cost[i]);
			}
			i++;
	}
	cout << ans;
}
