#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, s;
		int arr[200001];
		cin >> n >> s;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr,arr+n);
		
		int left = 1, right = arr[n-1]-arr[0];
		int ans = -1;
		while(left <= right){
			int mid = (left+right)/2;
			int cnt = 1;
			int diff = 0;
			for(int i = 1; i < n; i++){
				diff += arr[i]-arr[i-1];
				if(diff >= mid){
					cnt++;
					diff = 0;
				}
			}
			if(cnt >= s){
				left = mid + 1;
				ans = max(ans,mid);
			}else {
				right = mid - 1;
			}
		}
		cout << ans << endl;
	}
}