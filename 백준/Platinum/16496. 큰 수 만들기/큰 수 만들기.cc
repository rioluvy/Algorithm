#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(string a, string b){
	return a+b > b+a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	int n;
	vector<string> v(1001);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.begin()+n, compare);
    if(v[0] == "0") {
        cout << 0;
    }
    else {
        for(int i = 0; i < n; i++){
    		cout << v[i];
     	}
    }
}