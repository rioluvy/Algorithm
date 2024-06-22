#include <iostream>
#define mod 10007
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	for(int i = 5; i <= n; i++){
		arr[i] = (arr[i-3] * 3) % mod;
	}
	cout << arr[n];
}