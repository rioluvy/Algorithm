#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

int main() {
	ll n, m, p, ans = 1;
	cin >> n >> m >> p;
	while(n--){
		priority_queue<int> pq;
		int tmp, item = 0;
		for(int i = 0; i < m; i++){
			cin >> tmp;
			if(tmp == -1) item++;
			else pq.push(-tmp);
		}
		
		while(!pq.empty()){
			int t = -pq.top();
			while(p < t && item>0){
				item--;
				p*=2;
			}
			if(p < t) ans = 0;
			else p += t;
			
			pq.pop();
		}
		while(item>0) {
			p*=2;
			item--;
		}
	}
	cout << ans;
}