#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

vector<int> longest;

void bi(int element){

  int left,right,mid;

  left=0;right=longest.size()-1;

  while(left<right){

    mid = (left+right)/2;

    if(longest[mid]<element) left=mid+1;

    else right=mid;

  }

  longest[left]=element;

}

int main() {
    ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);
	int n;    cin >> n;

    int seq[1000001];

    

    for(int i=0;i<n;i++){

      cin >> seq[i];

    }

   

    for(int i=0;i<n;i++){

      if(i==0 || longest[longest.size()-1]<seq[i]) {

        longest.push_back(seq[i]);

        continue;

      }

      bi(seq[i]);

    }

    cout << longest.size();

}