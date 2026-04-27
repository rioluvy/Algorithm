#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int main() {
	int n,m;
	cin >> n;
	vector<int> root_seq(n+1,0);
	for(int i = 1; i < n+1; i++){
		cin >> root_seq[i];
	}
	cin >> m;
	while(m--){
		int l,r;
		cin >> l >> r;
		vector<int> num;
		vector<int> a;
		vector<int> seq(n+1,0);
		for(int i = 1; i < n+1; i++){
			seq[i] = root_seq[i];
		}
		for(int i = 1; i <= n; i++){
			if(seq[i] >= l && seq[i] <= r){
				num.push_back(i);
				a.push_back(seq[i]);
			}
		}
		sort(num.begin(),num.end());
		sort(a.begin(),a.end());
		for(int i = 0; i < r-l+1; i++){
			seq[num[i]] = a[i];
		}
		for(int i = 1; i < n+1; i++){
			cout << seq[i] << " ";
		}
		cout << endl;
	}
}