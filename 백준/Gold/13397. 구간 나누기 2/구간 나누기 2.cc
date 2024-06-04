#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int left = 10001;
	int right = 0;
	int arr[5001];
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		left = min(left,arr[i]);
		right = max(right,arr[i]);
	}
	right = right - left;
	left = 0;
	int ans = 10001;
	while(left <= right){
		int mid = (left+right)/2;
		int cnt = 0;
		int minN = arr[0], maxN = arr[0];
		for(int i = 1; i < n; i++){
			if(minN > arr[i]) minN = arr[i];
			if(maxN < arr[i]) maxN = arr[i];
			if(maxN - minN > mid){
				cnt++;
				minN = arr[i];
				maxN = arr[i];
			}
		}
		if(cnt < m){
			ans = mid;
			right = mid - 1;
		}else {
			left = mid + 1;
		}
	}
	
	cout << ans;
}