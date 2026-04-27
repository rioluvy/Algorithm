#include <iostream>
#include <vector>
#include <numeric>
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int n,q;
	cin >> n;
	vector<ll> water(n+1,0);
	vector<int> check(n+1,1);
	vector<ll> ans;
    ll tmp = 0;
	for(int i = 0; i < n; i++){
		cin >> water[i+1];
        tmp+=water[i+1];
	}
	ans.push_back(tmp);
	cin >> q;
	int com,num,x;
	for(int i = 0; i < q; i++){
		cin >> com;
		if(com==1){
			cin >> num >> x;
            if(check[num]){
              tmp -= water[num];
			water[num] = x;
			tmp += x;
            }else{
               water[num] = x;
             }
		
		}
		else{
			cin >> num;
			check[num] = 1-check[num];
			if(check[num]) tmp += water[num];
			else tmp -= water[num];
		}
		ans.push_back(tmp);
	}
	for(int i = 0; i < q+1; i++){
		cout << ans[i] << endl;
	}
}