#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll x,y;
	cin >> x >> y;
	ll tmp = x*y;
	cout << 2 << "\n";
	cout << tmp-x << "\n";
	cout << y-tmp;
}