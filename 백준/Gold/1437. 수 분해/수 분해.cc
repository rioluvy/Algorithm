#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 0 || n == 1) {
		cout << n;
		return 0;
	}
	int mx, re, ans;
	mx = n/3;re = n%3;
	ans = 1;
	if(re == 2) ans *= 2;
	else if(re == 1) {
		ans *= 4;
		mx -= 1;
	}
	
	for(int i = 0; i < mx; i++){
		ans *= 3;
		ans %= 10007;
	}
	cout << ans;
}