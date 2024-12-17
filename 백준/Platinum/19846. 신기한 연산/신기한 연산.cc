#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q, s, e, tmp = 97;
	vector<char> c;
	cin >> n >> m >> q;
	for(int i = 0; i < q; i++){
		cin >> s >> e;
	}
	while(true){
		c.push_back(tmp);
		m--;
		if(!m) break;
		else{
			c.push_back(tmp);
			m--;
			if(!m) break;
			tmp = 97 + ((tmp-97+1)%n);
		}
	}
	for(auto v : c) cout << char(v);
}