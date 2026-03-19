#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

ll ccw(pll a, pll b, pll c){
    ll tmp = (b.first-a.first) * (c.second-a.second) - (b.second-a.second) * (c.first-a.first);
    if(tmp > 0) return 1;
    else if(tmp == 0) return 0;
    else return -1;
}

int main(){
    FAST_IO
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    pii A = {x1,y1};
    pii B = {x2,y2};
    pii C = {x3,y3};
    pii D = {x4,y4};

    int abc = ccw(A,B,C);
    int abd = ccw(A,B,D);
    int cda = ccw(C,D,A);
    int cdb = ccw(C,D,B);

    if(abc*abd == 0 && cda * cdb == 0){
        if(A > B) swap(A,B);
        if(C > D) swap(C,D);

        if(A <= D && C <= B) cout << 1;
        else cout << 0;
        return 0;
    }

    if(abc * abd <= 0 && cda * cdb <= 0) cout << 1;
    else cout << 0;
}