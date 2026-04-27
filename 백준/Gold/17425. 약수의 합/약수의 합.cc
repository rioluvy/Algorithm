#include <iostream>
#define lint long long
#define endl "\n"
using namespace std;
lint arr[1000001];
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	for(int i = 1; i < 1000001; i++){
		for(int j = i; j < 1000001; j+=i){
			arr[j]+=i;
		}
	}
	for(int i = 1; i < 1000001; i++){
		arr[i] += arr[i-1];
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
}