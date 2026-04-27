#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;    cin >> n;
    int *seq = new int[n+1];
    for(int i=0;i<n;i++){
      cin >> seq[i];
    }
    
    int dp_as[1001];
    int dp_de[1001];
    for(int i=0;i<n;i++){
      dp_as[i]=1;
      for(int j=0;j<i;j++){
        if(seq[i]>seq[j]) dp_as[i] = max(dp_as[i],dp_as[j]+1);
      }
    }
    for(int i=n-1;i>=0;i--){
      dp_de[i]=1;
      for(int j=n-1;j>i;j--){
        if(seq[i]>seq[j]) dp_de[i] = max(dp_de[i],dp_de[j]+1);
      }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
      ans = max(ans,dp_as[i]+dp_de[i]-1);
    }
    cout << ans;
}