#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    int n,left,right,mid;
    cin >> n;
    int seq[1000001];
    vector<int> idx;
    vector<int> tmp;
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }
    for(int i=0;i<n;i++){
        if(i==0 || tmp[tmp.size()-1]<seq[i]){
            tmp.push_back(seq[i]);
            idx.push_back(tmp.size()-1);
            continue;
        }
        left = 0; right = tmp.size()-1;
        while(left<right){
            mid = (left+right)/2;
            if(tmp[mid]<seq[i]) left = mid+1;
            else right = mid;
        }
        tmp[left] = seq[i];
        idx.push_back(left);
    }
    cout << tmp.size() << endl;
    // for(auto v : idx) cout << v << " ";

    vector<int> ans;
    int check_idx=tmp.size()-1;
    for(int i=n-1;i>=0;i--){
        if(check_idx==idx[i]){
            ans.push_back(seq[i]);
            check_idx--;
        }
    }
    for(int i = tmp.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}