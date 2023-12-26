#include <iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,a,b,c,p;
    cin >> t;
    while(t--){
        int cnt = 0;
        cin >> a >> b >> c >> p;
        if(a%p==0) cnt++;
        if(b%p==0) cnt++;
        if(c%p==0) cnt++;
        cout << (cnt>1 ? 1:0) << "\n";
    }
}