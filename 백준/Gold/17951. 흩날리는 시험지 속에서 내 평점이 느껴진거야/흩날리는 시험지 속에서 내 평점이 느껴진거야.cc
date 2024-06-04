#include <iostream>
using namespace std;

int main() {
	int n, k, left = 0, right = 0;
	int arr[100001];
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		right += arr[i];
	}
	
	int ans = 0;
	while(left <= right){
		int mid = (left + right)/2;
		int s = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			s += arr[i];
			if(s >= mid){
				cnt++;
				s = 0;
			}
		}
		if(cnt >= k){
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << right;
}