#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	int l,n, ans = 0;
	l = s.length();
	n = stoi(s);
	
	for(int i = 0; i < l; i++){
		int num = n%10;
		n /= 10;
		if(num > 4) ans+=((num-1)*(pow(9,i)));
		else ans += (num * pow(9,i));
	}
	cout << ans;
}