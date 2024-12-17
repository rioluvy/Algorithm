#include <iostream>
#define endl "\n"
using namespace std;

int t, n;

int main() {
	cin >> t;
	while(t--){
		cin >> n;
		if(n%2==0){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		for(int i = 1; i <= n; i++){
			if(i%2){
				cout << i << " " << 2*n-i/2;
			}
			else{
				cout << i << " " << 2*n-n/2-i/2;
			}
			cout << endl;
		}
	}
}