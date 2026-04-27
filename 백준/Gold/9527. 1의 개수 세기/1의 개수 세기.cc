#include <iostream>

#include <algorithm>

#define ll long long

using namespace std;

ll cum[55];

ll sol(ll x){

  ll ans=x&1;   //x가 홀수면 1더하고 시작

  for(int i=54;i>0;i--){

    if(x&(1LL<<i)){   //최상위 켜져있는 비트 찾기

      ans += cum[i-1]+(x-(1LL<<i)+1);

      x -= (1LL<<i);

    }

  }

  return ans;

}

int main() {

	ll a,b;    cum[0]=1;

    for(int i=1;i<55;i++){

      cum[i]= 2*cum[i-1]+(1LL<<i);

    }

    cin >> a >> b;

    cout << sol(b) -sol(a-1);

    

}