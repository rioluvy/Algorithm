#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> p(100000,1);
    for(int i = 2; i*i <= 100000; i++){
    	if(p[i] == 1){
    		for(int j = i*i; j <= 100000; j += i){
    			p[j] = 0;
    		}
    	}
    }
    vector<int> prime;
    for(int i = 2; i <= 100000; i++){
    	if(p[i] == 1) {
    		prime.push_back(i);
    	}
    }
    while(t--){
    	int n;
    	cin >> n;
    	vector<int> arr(n);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	sort(arr.begin(),arr.end());
    	int ans = 2147483647;
    	for(int i = 0; i <= prime.size()-n; i++){
    		int tmp = 0;
    		for(int j = 0; j < n; j++){
    			tmp += abs(arr[j]-prime[i+j]);
    		}
    		ans = min(ans,tmp);
    	}
    	cout << ans << endl;
    }
}