#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,num;
    vector<int> block;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        block.push_back(num);
    }
    if(n == 1) {
        cout << block[0];
        return 0;
    }
    double avg,tmp = 0;
    sort(block.begin(),block.end());
    for(int i = 0; i < n; i++){
        tmp += block[i];
    }
    avg = tmp/n;
    cout << fixed;
    cout.precision(6);
    cout << (avg > block[n-2] ? avg : block[n-2]);
    
}