#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n";
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	int n, a, b;
	cin >> n;
	vector<pair<int,int>> seq;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		seq.push_back({a,b});
	}
	sort(seq.begin(),seq.end());
	vector<int> string;
	vector<int> idx;
	for(int i = 0; i < n; i++){
		if(i == 0 || string[string.size()-1] < seq[i].second){
			string.push_back(seq[i].second);
			idx.push_back(string.size()-1);
			continue;
		}
		int left,right,mid;
		left = 0; right = string.size()-1;
		while(left<right){
			mid = (left+right)/2;
			if(string[mid] >= seq[i].second) right = mid;
			else left = mid + 1;
		}
		string[left] = seq[i].second;
		idx.push_back(left);
	}

	vector<int> removing;
	int len = string.size();
	cout << n - len << endl;

	while(n--){
		if(idx[n] == len-1){
			len--;
			continue;
		}
		removing.push_back(seq[n].first);
	}
	sort(removing.begin(),removing.end());
	for(auto v : removing) cout << v << endl;
}