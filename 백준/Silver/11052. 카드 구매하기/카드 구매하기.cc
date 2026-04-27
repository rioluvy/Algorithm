#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

int main(){

	int n;    cin >> n;

    vector<int> card(n+1);

    vector<int> dp(n+1);

    for(int i=1;i<n+1;i++){

      cin >> card[i];

    }

    for(int i=1;i<n+1;i++){

      if (i==1){

        dp[1] = card[1];

        continue;

      }

      vector<int> tmp(i/2+2);

      tmp[0] = card[i];

      for(int j=1;j<(i/2+1);j++){

          tmp[j] = dp[j]+dp[i-j];

        }

      int m = *max_element(tmp.begin(),tmp.end());

      dp[i] = m;

    }

    cout << dp[n];

}