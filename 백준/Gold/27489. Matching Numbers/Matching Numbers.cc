#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t, n;

int main(){
    FAST_IO
	cin >> t;
	while(t--){
		cin >> n;
		if(n%2==0){
			cout << "No" << "\n";
			continue;
		}
		cout << "Yes" << "\n";
		for(int i = 1; i <= n; i++){
			if(i%2){
				cout << i << " " << 2*n-i/2;
			}
			else{
				cout << i << " " << 2*n-n/2-i/2;
			}
			cout << "\n";
		}
	}
}