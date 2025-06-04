#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	vector<int> ans;
	cin >> n >> k;
	if(k==0){
		cout << -1;
		return 0;
	}
	ans.push_back(k);
	for(int i = 1; i <= k-1; i++) ans.push_back(i);
	for(int i = k+1; i <= n; i++) ans.push_back(i);
	if(ans.size()==1) cout << k;
	else{
		cout << k;
		for(int i = 1; i < n; i++){
			cout << " " << ans[i];
		}
	}
}