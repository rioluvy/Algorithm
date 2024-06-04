#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	int n,c;
	cin >> n >> c;
	vector<int> house(n,0);
	for(int i = 0; i < n; i++){
		cin >> house[i];
	}
	sort(house.begin(),house.end());
	
	int left = 1, right = house[n-1]-house[0];
	int ans = 0;
	while(left <= right){
		int cnt = 1;
		int mid = (left+right)/2;
		int tmp = house[0];
		for(int i = 0; i < n; i++){
			if(tmp+mid <= house[i]) {
				cnt++;
				tmp = house[i];
			}
		}
		if(c > cnt) {
			right = mid-1;
		}
		else {
			left = mid+1;
			ans = mid;
		}
	}
	cout << ans;
}