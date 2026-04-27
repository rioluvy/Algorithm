#include <iostream>
using namespace std;

int n, x, l, c;
int cache[10001];

int main() {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> x;
    cache[0] = 1;
    for(int i = 0; i < n; i++){
    	cin >> l >> c;
    	for(int j = x; j >= 0; j--){
    		for(int k = 1; k <= c; k++){
    			if(j-l*k >= 0){
    				cache[j] += cache[j-l*k];
    			}
    		}
    	}
    }
    cout << cache[x];
}