#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#define endl "\n"
using namespace std;

string s;
int n, w, tmp, start[8] = {1,2,0,1,1,0,2,1};

int cal(string s){
	int tmpw = 0;
	for(int i = 0; i < s.length()-1; i++){
		if(s[i] != s[i+1]) tmpw++;
	}
	return tmpw;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	vector<int> ans;
	w = cal(s);
	n = s.length()/3;
	if(w >= 2*n){
		cout << 0;
		return 0;
	}
	for(auto &v : s) v -= '0';
	for(int i = 0; i < s.length(); i+=3){
		if(i == 0){
			tmp += (s[0]*4+s[1]*2+s[2]*1);
			if(start[tmp]) ans.push_back(start[tmp]);
			continue;
		}
		tmp = cal(s.substr(i-1,4));
		if(tmp >= 2) continue;
		s[i] = 1-s[i]; s[i+1] = 1-s[i+1];
		tmp = cal(s.substr(i-1,4));
		if(tmp >= 2){
			ans.push_back(i+1);
			continue;
		}
		s[i] = 1-s[i];s[i+1] = 1-s[i+1];
		s[i+1] = 1-s[i+1]; s[i+2] = 1-s[i+2];
		tmp = cal(s.substr(i-1,4));
		if(tmp >= 2){
			ans.push_back(i+2);
			continue;
		}
		
	}
	cout << ans.size() << endl;
	for(auto k : ans) cout << k << " ";
}