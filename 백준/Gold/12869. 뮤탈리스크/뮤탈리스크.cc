#include <iostream>
#include <algorithm>
using namespace std;

int hp[3];
int dp[61][61][61];

int rec(int a,int b,int c){
	if(a < 0) return rec(0,b,c);
	if(b < 0) return rec(a,0,c);
	if(c < 0) return rec(a,b,0);
	
	if(a == 0 && b == 0 && c == 0) return 0;
	int &ret  = dp[a][b][c];
	if(ret!=0) return ret;
	
	ret = 2147483647;
	ret = min(ret,rec(a-9,b-3,c-1)+1);
	ret = min(ret,rec(a-9,b-1,c-3)+1);
	ret = min(ret,rec(a-3,b-9,c-1)+1);
	ret = min(ret,rec(a-3,b-1,c-9)+1);
	ret = min(ret,rec(a-1,b-3,c-9)+1);
	ret = min(ret,rec(a-1,b-9,c-3)+1);
	return ret;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> hp[i];
	}
	cout << rec(hp[0],hp[1],hp[2]);
}