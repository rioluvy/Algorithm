#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    stack<int> a;

    int tmp = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') a.push(-1);
        else if(s[i] == 'H') a.push(1);
        else if(s[i] == 'C') a.push(12);
        else if(s[i] == 'O') a.push(16);
        else if(s[i] >= '2' && s[i] <= '9'){
            tmp = a.top() * (s[i]-'0');
            a.pop();
            a.push(tmp);
        }
        else{
            tmp = 0;
            while(true){
                if(a.top() == -1){
                    a.pop();
                    a.push(tmp);
                    break;
                }
                tmp += a.top();
                a.pop();
            }
        }
    }
    while(!a.empty()){
        ans += a.top();
        a.pop();
    }
    cout << ans;
}