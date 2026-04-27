#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define hash 100
using namespace std;

int n,a,b,c,d,idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> flower;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        flower.push_back({a*hash+b,c*hash+d});
    }
    sort(flower.begin(),flower.end());
    // for(int i = 0; i < n; i++){
    //     cout << flower[i].first << " " << flower[i].second << endl;
    // }
    int cnt = 0, end = 301, tmpEnd = 0, saveEnd;
    bool flag = false;
    idx = 0;
    while(idx < n){
        saveEnd = end;
        while(true){
            if(flower[idx].first <= end && end < flower[idx].second){
                tmpEnd = max(tmpEnd, flower[idx].second);
                if(tmpEnd > 1130){
                    cnt++;
                    end = tmpEnd;
                    break;
                }
                idx++;
                
            }
            else{
                if(flower[idx].first <= tmpEnd && flower[idx].first >= saveEnd){
                    end = tmpEnd;
                    cnt++;
                }
                else idx++;
                break;
            }
        }
        if(end > 1130) break;
    }
    if(end > 1130) cout << cnt;
    else cout << 0;
}