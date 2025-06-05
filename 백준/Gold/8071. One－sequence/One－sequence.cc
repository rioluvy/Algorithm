#include <iostream>
#include <cmath>
using namespace std;

int psum(int k, int a1,int sum){
	int tp = k*(a1+1+a1+k)/2;
	int tm = k*(a1-1+a1-k)/2;
	if(abs(sum-tp) <= abs(sum-tm)) return 0;
	else return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    
	int n,s,tmp = 0;
	cin >> n >> s;
	if(abs(s)%2 != (n*(n-1)/2)%2 || abs(s) > n*(n-1)/2){
		cout << "NIE";
		return 0;
	}
	cout << tmp << "\n";
	for(int i = 1; i < n; i++){
		if(psum(n-i,tmp,s)==0){
			tmp++;
			s-=tmp;
		}else{
			tmp--;
			s-=tmp;
		}
		cout << tmp << "\n";
	}
}