#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int n, q = 20, re, t;
int prime[5000001];
vector<int> v;

void net(){
	for(int i = 2; i*i <= n; i++){
		if(!prime[i]){
			for(int j = i*i; j <= n; j+=i){
				prime[j] = 1;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(!prime[i]) v.push_back(i);
	}
}

int main() {
	cin >> n;
	t = n;
	net();
	
	int left = 0, right = v.size()-1;
	while(left <= right && q > 0){
		int mid = (left+right)/2;
		cout << "? " << v[mid] << endl;
		cout << flush;
		cin >> re;
		if(re){
			left = mid + 1;
		} else{
			right = mid - 1;
			t = v[mid];
		}
		q--;
	}
	cout << "! " << t << endl;
	cout << flush;
}