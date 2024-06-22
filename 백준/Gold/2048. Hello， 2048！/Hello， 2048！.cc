#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int t,l,r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> t;
	while(t--){
		cin >> l >> r;
		if(r >= 4) {
			cout << r << endl;
			continue;
		}
		int num = 0;
		for(int i = r; i >= l; i--){
			num += (pow(2,i)*pow(10,r-i));
		}
		int cnt = 0;
		while(num % 2 == 0){
			num /= 2;
			cnt++;
		}
		cout << cnt << endl;
	}
}