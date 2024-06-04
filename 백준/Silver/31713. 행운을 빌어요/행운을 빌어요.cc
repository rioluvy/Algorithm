#include <iostream>
#define endl "\n"
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int a, b, ans = 0;
		cin >> a >> b;
		while(b > a*4) {
			a++;
			ans++;
		}
		while(b < a*3) {
			b++;
			ans++;
		}
		cout << ans << endl;
	}
}