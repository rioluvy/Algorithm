#include <iostream>
using namespace std;

int main() {
	int n, c = 1;
	cin >> n;
	if(n <= 3){
		cout << 1 << "\n";
		for(int i = 0; i < n; i++){
			cout << c << " ";
		}
		return 0;
	}
	cout << (n-3)/2 + (n-3)%2 + 1 << "\n";
	cout << c << " " << c << " " << c << " ";
	for(int i = 4; i <= n; i++){
		if(i%2==0) c++;
		cout << c << " ";
	}
}