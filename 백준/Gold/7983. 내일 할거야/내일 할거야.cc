#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

bool compare(pii x, pii y){
	return x.second > y.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n, d, t;
	cin >> n;
	vector<pii> assigns(n);
	for(int i = 0; i < n; i++){
		cin >> d >> t;
		assigns[i] = {d,t};
	}
	sort(assigns.begin(),assigns.end(),compare);
	int ans = assigns[0].second;
	for(auto a : assigns){
		int due = a.second;
		if(due < ans) ans = due;
		ans -= a.first;
	}
	cout << ans;
}