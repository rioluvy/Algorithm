#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	while(m--){
		int s = 0;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			s += arr[i];
		}
		if(!s){
			for(int i = 0; i < n; i++) cout << 1 << " ";
			cout << endl;
			continue;
		}
		int tmp = 0;
		for(int i = 0; i < n; i++){
			tmp += arr[i];
			if(tmp == s/2){
				for(int j = 0; j <= i; j++) cout << 1 << " ";
				for(int j = i+1; j < n; j++) cout << -1 << " ";
				cout << endl;
				break;
			}
		}
	}
}