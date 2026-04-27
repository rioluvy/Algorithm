#include <iostream>
#include <cstring>
#define mod 1000000007
#define ll long long
using namespace std;

int cache[1001][1001];

ll dp(int n, int m){
	if(n == 1 || m == 1){
		return cache[n][m] = 1;
	}
	if(cache[n][m] != 0) return cache[n][m];
	return cache[n][m] = (dp(n-1,m) + dp(n,m-1) + dp(n-1,m-1)) % mod;
}

int main() {
	int n,m;
	cin >> n >> m;
	memset(cache,0,sizeof(cache));
	cout << dp(n,m);
}