#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    FAST_IO
    int n;
    cin >> n;
    vector<int> m(n);
    vector<int> w(n);
    for(auto &i:m) cin >> i;
    for(auto &i:w) cin >> i;

    sort(m.begin(),m.end());
    sort(w.begin(),w.end(),[](const auto& a, const auto& b){
        return a > b;
    });

    int a = 0, b = 0, ans = 0;
    while(true){
        if(a == n || b == n) break;
        if(m[a] < 0 && w[b] > 0){
            if(abs(m[a]) <= abs(w[b])) {
                b++;
            }
            else{
                a++; b++;
                ans++;
            }
        }
        else if(m[a] > 0 && w[b] < 0){
            if(abs(m[a]) >= abs(w[b])){
                b++;
            }
            else{
                a++; b++;
                ans++;
            }
        }
        else if(m[a] < 0) a++;
        else if(w[b] > 0) b++;
    }
    cout << ans << "\n";
}