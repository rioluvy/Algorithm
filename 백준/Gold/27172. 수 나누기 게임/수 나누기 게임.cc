#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

int main() {
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n, num;    cin >> n;

    int card[1000001];

    int check[1000001];

    int player[1000001]={0,};

    for(int i=0;i<n;i++){

      cin>>card[i];

      check[card[i]]=1;

    }

    for(int i=0;i<n;i++){

      num=card[i];

      for(int j=num*2;j<1000001;j+=num){

        if(check[j]){

          player[num]++;

          player[j]--;

        }

      }

    }

    for(int i=0;i<n;i++){

      cout << player[card[i]] << " ";

    }

}