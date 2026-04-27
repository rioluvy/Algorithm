#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

struct diamond{

    double w;

    double c;

};

int main() {

	int t;    cin >> t;

    while(t--){

      int n, w, c;

      cin >> n;

      diamond d[201];

      int dp[201];

      for(int i=0;i<n;i++){

        cin >> d[i].w >> d[i].c;

      }

      for(int i=0;i<n;i++){

        dp[i] = 1;

        for(int j=0;j<i;j++){

          if(d[i].w>d[j].w && d[i].c<d[j].c){

            if(dp[i]<=dp[j]){   

              dp[i]=dp[j]+1;

            }

          }

        }

      }

      cout << *max_element(dp,dp+n)<< endl;

    }

	

}