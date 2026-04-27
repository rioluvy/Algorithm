#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define endl "\n"
using namespace std;

int n, num;
vector<int> arr(100001,0);

void fac(int a, bool check){
	int tmp = sqrt(a);
	if(check){
		for(int i = 2; i <= tmp; i++){
			while(a%i == 0) {
				arr[i]++;
				a /= i;
			}
		}
		if(a > 1) arr[a]++;
	}
	else {
		for(int i = 2; i <= tmp; i++){
			while(a%i == 0) {
				arr[i]--;
				a /= i;
			}
		}
		if(a > 1) arr[a]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	int inputCnt = 2*n-1;
	bool flag = true;
	bool zeroCheck = false;
	string s;
	for(int i = 1; i < inputCnt+1; i++){
		cin >> s;
		if(i%2 == 0){
			if(s == "*") flag = true;
			else flag = false;
			continue;
		}
		if(s == "0") zeroCheck = true;
		fac(abs(stoi(s)),flag);
	}
	if(zeroCheck) {
		cout << "mint chocolate";
		return 0;
	}
	for(int i = 2; i < 100001; i++){
		if(arr[i] < 0) {
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
}