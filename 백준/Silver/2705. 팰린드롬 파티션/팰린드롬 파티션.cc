#include <iostream>
#define endl "\n"
using namespace std;

int dp[1001];

int rec(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	if(dp[n] != 0) return dp[n];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if((((n-i)/2)) * 2 + i == n) cnt += rec((n-i)/2);
	}
	return dp[n] = (cnt+1);
}



int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << rec(n) << endl;
	}
}