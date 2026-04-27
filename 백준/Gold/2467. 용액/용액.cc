#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

#define endl "\n"

using namespace std;

int main() {

    int n,start,end,a,b;

    cin >> n;

    int *sol=new int[n];

    for(int i=0;i<n;i++){

      cin >> sol[i];

    }

    start =0; end=n-1;

    int value = abs(sol[start]+sol[end]);

    a=sol[start]; b= sol[end];

    

    while(start<end){

      int tmp = sol[start]+sol[end];

      int dis = abs(tmp);

      if (value>dis){

        value = dis;

        a = sol[start];

        b = sol[end];

      }

      if(tmp<0) start++;

      else end--;

    }

    cout << a << " " << b;

}