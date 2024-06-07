#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, tmp;
string s,t = "";
vector<string> v;
vector<string> zero_v;
vector<string> copyV;

bool compare(string a, string b){
    return a+b < b+a;
}

bool compare2(string a, string b){
    return a+t+b < b+t+a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s[0] != '0') v.push_back(s);
        else zero_v.push_back(s);
        
    }
    for(int i = 0; i < v.size(); i++){
        copyV.push_back(v[i]);
    }
    if(v.size() == 0) {
        cout << "INVALID";
        return 0;
    }
    sort(v.begin(), v.end(), compare);
    if(zero_v.size() == 0) {
        for(int i = 0; i < n; i++){
            cout << v[i];
        }
    }
    else{
        sort(zero_v.begin(), zero_v.end(), compare);
        for(int i = 0; i < zero_v.size(); i++) t += zero_v[i];
        sort(copyV.begin(), copyV.end(), compare2);
        cout << copyV[0] << t;
        int idx = find(v.begin(),v.end(),copyV[0])-v.begin();
        for(int i = 0; i < v.size(); i++){
            if(copyV[0] == v[i]) {
                tmp = i;
                break;
            }
        }
        for(int i = 0; i < v.size(); i++) {
            if(i == tmp) continue;
            cout << v[i];
        }
    }

}