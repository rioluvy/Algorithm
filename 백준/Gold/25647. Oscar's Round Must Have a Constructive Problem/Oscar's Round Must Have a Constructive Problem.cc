#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> A(n);
		for(auto &i : A) cin >> i;
		int flag = 0;
		for(int i = 0; i < n-1; i++){
			if(A[i] != A[i+1]) flag=1;
		}
		if(!flag){
			cout << "NO\n";
			continue;
		}
		vector<int> ans(n,0);
		vector<int> tmp;
		int one = -1;
		for(int i = 0; i < n; i++){
			ans[i] = i+1;
			if(ans[i] == A[i]) tmp.push_back(i);
		}
		if(tmp.size()==1) {
			for(int i = 0; i < n; i++){
				if(ans[tmp[0]] != A[i]) one = i;
			}
			swap(ans[tmp[0]],ans[one]);
		}
		else if(tmp.size() > 1){
			for(int i = 0; i < tmp.size()-1; i++){
				swap(ans[tmp[i]],ans[tmp[i+1]]);
			}
		}
		cout << "YES\n";
		for(auto v:ans) cout << v << " ";
		cout << "\n";
	}
}