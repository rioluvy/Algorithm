#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll a,b,c,d,u,ans = 0;
bool checkA, checkB;

void ap(){
	if(a <= u) {
		ans += ((u-a)/b+1);
		checkA = true;
	}
}

void gs(){
	if(d == 1) {
		if(c <= u){
			ans++;
			checkB = true;
		}
	}
	else {
		ll tmp = c;
		while(true){
			if(tmp <= u) {
				tmp *= d;
				ans++;
				checkB = true;
			}
			else break;
		}
	}
}

int main() {
	cin >> a >> b >> c >> d >> u;
	ap();
	gs();
	if(checkA && checkB){
		ll tmp2 = c;
		if(d == 1){
			if(a <= c && ((c-a)%b == 0)) ans--;
		}
		else{
			while(tmp2 <= u){
				if(tmp2 >= a){
					if((tmp2-a)%b == 0) {
						ans--;
					}
				}
				tmp2 *= d;
				
			}	
		}
	}
	cout << ans;
}