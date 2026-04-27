#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

int main() {

	int n;    cin >> n;

    int s[1001] = {0,};

    int dp[1001] = {0,};

    for(int i=1;i<n+1;i++){

      cin >>s[i];

    }

 

    for(int i=1;i<n+1;i++){

      dp[i]=1;

      for(int j=1;j<i;j++){

        if(s[i]<s[j]){

          dp[i]=max(dp[j]+1,dp[i]);

        }

      }

    }

    cout << *max_element(dp,dp+n+1);

}