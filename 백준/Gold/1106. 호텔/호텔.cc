#include <iostream>
#include <algorithm>
using namespace std;

int cost[21];
int client[21];
int dp[1001];
int c,n;

int rec(int num){
	if(num<=0) return 0;
	int &ret = dp[num];
	if(ret!=0) return ret;
	
	ret = 2147483647;
	for(int i = 0; i < n; i++){
		ret = min(ret, rec(num-client[i])+cost[i]);
	}
	return ret;
}


int main() {
	cin >> c >> n;
	for(int i = 0; i < n; i++){
		cin >> cost[i] >> client[i];
	}
	cout << rec(c);
}