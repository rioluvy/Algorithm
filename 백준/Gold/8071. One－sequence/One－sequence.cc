#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;

int psum(int k, int start,int sum){
	int tp = k*(start+1+start+k)/2;
	int tm = k*(start-1+start-k)/2;
	if(abs(sum-tp) <= abs(sum-tm)) return 0;
	else return 1;
}

int main() {
	int n,s,tmp = 0;
	cin >> n >> s;
	if(abs(s)%2 != (n*(n-1)/2)%2 || abs(s) > n*(n-1)/2){
		cout << "NIE";
		return 0;
	}
	cout << tmp << endl;
	for(int i = 1; i < n; i++){
		if(psum(n-i,tmp,s)==0){
			tmp++;
			s-=tmp;
		}else{
			tmp--;
			s-=tmp;
		}
		cout << tmp << endl;
	}
}