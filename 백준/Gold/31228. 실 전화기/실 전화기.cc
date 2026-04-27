#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	int c;
	while(b !=0){
		c = a%b;
		a=b;
		b=c;
	}
	return a;
}

int main() {
	ll n, k, ans;
	cin >> n >> k;
	if(k>n/2) k = n-k;
	if(n%k==0) ans = 0;
	else{
		int tmp = gcd(n,k);
		n /= tmp;
		k /= tmp;
		ans = n*(k-1);
	}
	cout << ans;
}