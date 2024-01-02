#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, k;
    cin >> n;
    vector<int> up(n+1,0);
    vector<int> down(n+1,0);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k>0) up[k]++;
        else down[-k]++;
    }

    for(int i = 1; i < n+1; i++){
        up[i] += up[i-1];
        down[n-i] += down[n-i+1];
    }

    for(int i = 0; i < n+1; i++){
        up[i] += down[i];
    }

    for(int i = 0; i < n+1; i++){
        if(n-i == up[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto v: ans) cout << v << " ";
}