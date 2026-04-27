#include <iostream>
using namespace std;

int main() {
	long long n,tmp = 0,sum = 0;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
		tmp += (arr[i]/2);
	}
	if(sum%3==0 && tmp*3 >= sum) cout << "YES";
	else cout << "NO";
	
}