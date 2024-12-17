#include <iostream>
#include <vector>
using namespace std;
	
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, m, a, b;
	vector<int> as, ds;
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		cin >> a >> b;
		if(a<b) as.push_back(i);
		else ds.push_back(i);
	}
	if(as.size()>ds.size()){
		cout << ds.size() << "\n";
		for(auto v:ds) cout << v << "\n";
	}
	else{
		cout << as.size() << "\n";
		for(auto v:as) cout << v << "\n";
	}
}