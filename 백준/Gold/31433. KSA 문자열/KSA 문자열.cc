#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long
#define endl "\n"

using namespace std;

char ksa[4] = {'K','S','A'};
int trial(string s, int start){
	int r = 0;
	int len = s.size();
	for(int i = 1; i < len+1; i++){
		if(s[i-1] == ksa[(i-r-1)%3]) continue;
		r++;
	}
	if(r >= start) return 2*r;
	return 2*start;
}
int main() {
	string s;
	cin >> s;
	int ans = min({trial(s,0), trial("K"+s,1), trial("KS"+s,2)});
	cout << ans;
}