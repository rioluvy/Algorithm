#include <iostream>
#define ll long long
using namespace std;

int main() {
	int n, cnt, re;
	cin >> n;
	if(n/10 == 0){
		cout << 1;
		return 0;
	}
	ll ans = 0;
	for(int i = 9; i >= 1; i--){
		cnt = n/i;
		re = n%i;
		if(cnt%2 == 1){
			re += i;
			cnt--;
		}
		ans += cnt;
		if(re != 0 && re/10 == 0){
			ans++;
			break;
		}
        n = re;
	}
	cout << ans;
}