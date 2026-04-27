#include <iostream>
#define ll long long
#define endl "\n"

using namespace std;
int num[10];
int main() {
	int arr[10] = {0,111,22,33,4,55,6,77,8,9};
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	cout << "YES" << endl << arr[num[0]];
}