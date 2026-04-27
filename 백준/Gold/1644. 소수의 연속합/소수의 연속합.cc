#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#define endl "\n"

#define MAX 4000000

using namespace std;

int prime[MAX+1]={0,}; //소수면 0

int main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;    cin >>n;

	if(n==1){ 

		cout <<0;

		return 0;

}

	vector<int> sum_prime;

  prime[1]=1;

  for(int i=2;i<(int)sqrt(n)+1;i++){

		if(prime[i]) continue;

		for(int j=i*2;j<n+1;j+=i){

      prime[j]=1;

	  }

	}

	int tmp=0;

	sum_prime.push_back(tmp);

	for(int i=1;i<n+1;i++){

		if(!prime[i]){

			tmp+=i;

			sum_prime.push_back(tmp);

		}

}

    

	int left=0,right=1,cnt=0;

	while(left<=right){

		tmp=sum_prime[right]-sum_prime[left];

    if(tmp>n) left++;

		else if(tmp<n) right++;

		else {

			cnt++;

      left++;

			right++;

		}

		if(right==sum_prime.size()) break;

	}

	cout<<cnt;

}