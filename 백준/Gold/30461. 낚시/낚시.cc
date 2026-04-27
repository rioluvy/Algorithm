#include <iostream>
#define endl "\n"
using namespace std;

int prefix_sum[2001][2001];
int dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,m,q,fish;
	cin >> n >> m >> q;
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			cin >> fish;
			prefix_sum[i][j] += (prefix_sum[i-1][j] + fish);
			dp[i][j] = dp[i-1][j-1]+prefix_sum[i][j];
		}
	}
	while(q--){
		int w,p;
		cin >> w >> p;
		cout << dp[w][p] << endl;
	}
}