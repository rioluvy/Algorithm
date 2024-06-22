#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n-1);
	int s, d;
	cin >> s;
	for(int i = 0; i < n-1; i++){
		cin >> d;
		arr[i] = d-s;
		s = d;
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i = 0; i < n-k; i++){
		ans += arr[i];
	}
	cout << ans;
}