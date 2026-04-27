#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cout.tie(0);
	int n,i;
	cin >> n;
	for(i = 1; i <= n; i+=2) cout << i << " ";
	for(n&1 ? (i = n-1) : (i = n); i > 0; i-=2) cout << i << " ";
}