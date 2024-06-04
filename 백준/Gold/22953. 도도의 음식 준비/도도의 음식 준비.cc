#include <iostream>
#define lint long long
using namespace std;

int n, k, c;
int arr[11];
lint ans = 1000000000000;

lint bi(){
	lint left = 1, right = 1000000000000;
	while(left <= right){
		lint mid = (left+right)/2;
		lint food = 0;
		for(int i = 0; i < n; i++){
			food += (mid/arr[i]);
		}
		
		if(food >= k) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else left = mid + 1;
	}
	return 0;
}

void trial(int cnt, int idx = 0){
	if(cnt==0){
		bi();
		return;
	}
	for(int i = idx; i < n; i++){
		if(arr[i] > 1){
			arr[i]--;
			trial(cnt-1,i);
			arr[i]++;
		}
		else
			trial(cnt-1,i);
	}
}
int main() {
	cin >> n >> k >> c;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	trial(c);
	cout << ans;
}