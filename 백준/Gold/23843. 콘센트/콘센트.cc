#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, m, ans;
	cin >> n >> m;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	sort(arr.begin(),arr.end(), greater<>());
	priority_queue<int, vector<int>, greater<int>> pq;
	int t = 0;
	for(int i = 0; i < n; i++){
		if(pq.size() < m) {
			pq.push(t+arr[i]);
			continue;
		}
		t = pq.top();
		while(pq.size() > 0 && t == pq.top()){
			pq.pop();
		}
		pq.push(t+arr[i]);
	}
	while(!pq.empty()){
		ans = pq.top();
		pq.pop();
	}
	cout << ans;
}