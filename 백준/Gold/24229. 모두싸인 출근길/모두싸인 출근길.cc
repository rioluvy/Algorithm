#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,a,b;
	cin >> n;
	vector<pair<int,int>> arr;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr.push_back({a,b});
	}
	sort(arr.begin(),arr.end());
	vector<pair<int,int>> road;
	
	for(int i = 0; i < n-1; i++){
		bool flag1 = false, flag2 = false;
		if(arr[i].second >= arr[i+1].first){
			arr[i+1].first = arr[i].first;
			flag1 = true;
		}
		if(arr[i].second >= arr[i+1].second){
			arr[i+1].second = arr[i].second;
			flag2 = true;
		}
		if(flag1 && flag2) continue;
		road.push_back(arr[i]);
	}
	road.push_back(arr[n-1]);
	
	int i = 1;
	int max_jump = road[0].second-road[0].first + road[0].second;
	int ans = road[0].second;
	while(i < road.size()){
		if(road[i].first > max_jump) break;
		max_jump = max(max_jump,road[i].second-road[i].first + road[i].second);
		ans = road[i].second;
		i++;
	}
	cout << ans;
}