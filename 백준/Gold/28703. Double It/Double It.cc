#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, num;
	cin >> n;
	priority_queue<int> maxPq;
	priority_queue<int, vector<int>, greater<int>> minPq;
	for(int i = 0; i < n; i++){
		cin >> num;
		maxPq.push(num);
		minPq.push(num);
	}
	
	int limit = maxPq.top();
	int diff = 1000000001;
	while(minPq.top() <= limit){
		int mn = minPq.top();
		int mx = maxPq.top();
		diff = min(diff, mx-mn);
		minPq.pop();
		minPq.push(mn*2);
		maxPq.push(mn*2);
	}
	cout << diff;
}