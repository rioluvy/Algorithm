#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t, n, m, cache[10][1<<10];
char arr[10][11];
vector<int> ways;

int main(){
    FAST_IO
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < (1 << m); i++){
            if((i & (i >> 1)) == 0){
                ways.push_back(i);
            }
        }

        int blocked[10] = {0,};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 'x')
                    blocked[i] |= (1<<j);
            }
        }

        for(int mask:ways){
            if((mask & blocked[0]) == 0){
                cache[0][mask] = __builtin_popcount(mask);
            }
        }
        for(int i = 1; i < n; i++){
            for(auto mask:ways){
                if(mask & blocked[i]) continue;
                for(auto prev:ways){
                    if(prev & blocked[i-1]) continue;
                    if(mask & (prev << 1)) continue;
                    if(mask & (prev >> 1)) continue;
                    cache[i][mask] = max(cache[i][mask],cache[i-1][prev]+__builtin_popcount(mask));
                }
            }
        }
        cout << *max_element(cache[n-1],cache[n-1]+(1<<m)) << "\n";

        ways.clear();
        memset(cache,0,sizeof(cache));
    }

}