#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
	int n,m,card;
	cin >> n >> m;
	priority_queue<ll> pq;
	for(int i = 0 ; i < n; i++){
		cin >> card;
		pq.push(-card);
	}
	while(m--){
		ll tmp1, tmp2, sum;
		tmp1 = pq.top();
		pq.pop();
		tmp2 = pq.top();
		pq.pop();
		sum = tmp1 + tmp2;
		pq.push(sum);
		pq.push(sum);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += (-pq.top());
		pq.pop();
	}
	cout << ans;
}