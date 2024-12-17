#include <iostream>
#include <string>
using namespace std;

int main() {
	char dna[4] = {'A','G','C','T'};
	int cnt[4] = {0,0,0,0};
	int n,idx=0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			if(s[i] == dna[j]) cnt[j]++;
		}
	}
	for(int i=0;i<4;i++) {
		if(cnt[i] < cnt[idx]) idx=i;
	}
	cout << cnt[idx] << "\n";
	for(int i=0;i<n;i++) cout << dna[idx];
}