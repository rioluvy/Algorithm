#include <iostream>
#include <algorithm>
#define lint long long

using namespace std;

int main() {
	lint n, k;
	cin >> n >> k;
	lint day[1000001];
	for(int i = 0; i < n; i++){
		cin >> day[i];
	}
	
	lint left = 1, right = 2000000000;
	lint a, l, diff, ans;
	while(left <= right){
		lint mid = (left+right)/2;
		lint cash = 0;
		for(int i = 1; i <= n; i++){
			if(i == n) {
				a = mid;
				l = 1;
				diff = mid;
			}
			else{
				diff = day[i] - day[i-1];
				if(diff > mid) diff = mid;
				a = mid, l = mid - (diff-1);
			}
			cash += (diff*(a+l)/2);
			
		}
		if(cash >= k) {
			ans = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << ans;
}