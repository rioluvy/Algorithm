#include <iostream>
using namespace std;
int n, k, tmp;
int arr[100001];
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		arr[i] = arr[i-1] + tmp;
	}
	int ans = -1000000000;
	for(int i = k; i <= n; i++){
		int diff = arr[i] - arr[i-k];
		ans = max(ans,diff);
	}
	cout << ans;
}