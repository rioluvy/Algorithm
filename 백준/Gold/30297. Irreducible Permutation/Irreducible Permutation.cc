#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int t, n, m, tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> arr(n,0);
		vector<int> ans;
		for(auto &i : arr) cin >> i;
		m = arr[0];
		for(int i = 0; i < n-1; i++){
			m = max(arr[i],m);
			if(i+1 >= m){
				m = arr[i+1];
				tmp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = tmp;
				ans.push_back(i+1);
			}
		}
		if(ans.size()!=0){
			cout << ans.size() << endl;
			for(auto v:ans) cout << v << " ";
		}else{
			cout << 0 << endl;
		}
		cout << endl;
	}
}