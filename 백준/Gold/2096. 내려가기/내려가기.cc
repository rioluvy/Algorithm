#include <iostream>
#include <algorithm>
using namespace std;

int dp_max[2][3];
int dp_min[2][3];

int main() {
	int n,a,b,c;
	cin >> n;
	int tmp = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		dp_max[tmp][0] = max(dp_max[1-tmp][0],dp_max[1-tmp][1]) + a;
		dp_max[tmp][1] = max({dp_max[1-tmp][0],dp_max[1-tmp][1],dp_max[1-tmp][2]}) + b;
		dp_max[tmp][2] = max(dp_max[1-tmp][1],dp_max[1-tmp][2]) + c;
		
		dp_min[tmp][0] = min(dp_min[1-tmp][0],dp_min[1-tmp][1]) + a;
		dp_min[tmp][1] = min({dp_min[1-tmp][0],dp_min[1-tmp][1],dp_min[1-tmp][2]}) + b;
		dp_min[tmp][2] = min(dp_min[1-tmp][1],dp_min[1-tmp][2]) + c;
		
		tmp = 1-tmp; //0,1 전환
	}
	cout << max({dp_max[1-tmp][0],dp_max[1-tmp][1],dp_max[1-tmp][2]}) << " " << min({dp_min[1-tmp][0],dp_min[1-tmp][1],dp_min[1-tmp][2]});
}