#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

#include <limits.h>

#define endl "\n"

int MAX = INT_MAX;

using namespace std;

int main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,s,tmp=0;	cin >> n >> s;

	int seq[100001] = {0,};

  vector<int> sum_seq;

	sum_seq.push_back(0);

	for(int i=1;i<n+1;i++){

		cin >> seq[i];

		tmp+=seq[i];

		sum_seq.push_back(tmp);

	}

	int left=0,right=1,len=MAX;

  while(left<=right && right < sum_seq.size()){

		tmp=sum_seq[right]-sum_seq[left];

		if(tmp>=s) {

			len=min(right-left,len);

			left++;

		}else right++;

	}

	if(len==MAX) cout << 0;

	else cout << len;

}