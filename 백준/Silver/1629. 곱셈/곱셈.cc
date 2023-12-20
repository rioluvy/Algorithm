#include <iostream>
using namespace std;
int c;
int fpower(int a, int b){
    if(b==0) return 1;
    long long tmp = fpower(a,b/2);
    if(b%2==1) return (((tmp*tmp)%c)*a)%c;
    else return (tmp*tmp)%c;
}
int main(){
    int a,b;
    cin >> a >> b >> c;
    int ans = fpower(a,b);
    cout << ans;
}