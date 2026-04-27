#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
	int n,k,m,v,c,bag_size;
	int bag[300001];
	pair<int,int> jewel[300001];
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> m >> v;
		jewel[i] = {m,v};
	}
	sort(jewel,jewel+n);
	for(int i = 0; i < k; i++){
		cin >> c;
		bag[i] = c;
	}
	sort(bag, bag+k);
	
	ll value = 0, j = 0;
	priority_queue<int> pq;
	for(int i = 0; i < k; i++){
		bag_size = bag[i];
		while(jewel[j].first <= bag_size && j < n){
			pq.push(jewel[j].second);
			j++;
		}
		if(!pq.empty()){
			value += (1LL*pq.top());
			pq.pop();
		}
	}
	cout << value;
}