#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k;
string s,ans = "";
vector<string> v(n);

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        sort(s.begin(),s.end());
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < k; i++) ans += v[i];
    sort(ans.begin(),ans.end());
    cout << ans;
}