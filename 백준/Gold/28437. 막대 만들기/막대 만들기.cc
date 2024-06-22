#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cin >> q;
	vector<int> L(q);
	for(int i = 0; i < q; i++){
		cin >> L[i];
	}
	int mx = *max_element(L.begin(),L.end());
	vector<int> dp(mx+1);
	for(int i = 0; i < n; i++){
		if(A[i] <= mx) dp[A[i]]++;
	}

	for(int i = 2; i < mx+1; i++){
		for(int j = 1; j * j <= i; j++){
			if(i%j == 0){
				dp[i] += dp[j];
				if(j != 1 && j * j != i){
					dp[i] += dp[i/j];
				}
			}
		}
	}
	for(int i = 0; i < q; i++){
		cout << dp[L[i]] << " ";
	}
}