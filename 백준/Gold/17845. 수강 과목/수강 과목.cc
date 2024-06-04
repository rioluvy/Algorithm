#include <iostream>
using namespace std;

int n, k;
int cache[10001];
int im[1001];
int t[1001];

int main() {
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> im[i] >> t[i];
	}
	for(int i = 0; i < k; i++){
		for(int j = n; j >= t[i]; j--){
			cache[j] = max(cache[j],cache[j-t[i]]+im[i]);
		}
	}
	cout << cache[n];
}