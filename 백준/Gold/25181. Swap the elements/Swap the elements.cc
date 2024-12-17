#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

bool compare(pii x, pii y){
	return x.second < y.second;
}
int main() {
	int n, tmp;
	cin >> n;
	vector<pii> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(),A.end());
	tmp = n/2;
	if(n%2) tmp = n/2+1;
	for(int i = 0; i < tmp; i++){
		if(A[i].first == A[i+n/2].first){
			cout << -1;
			return 0;
		}
	}
	int idx;
	for(int i = 0; i < tmp; i++){
		int idx = A[i].second;
		A[i].second = A[i+n/2].second;
		A[i+n/2].second = idx;
	}
	sort(A.begin(),A.end(),compare);
	for(auto x:A) cout << x.first << " ";
}