#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

#define endl "\n"

using namespace std;

int main() {

    int n,start,end,a,b,c;

    cin >> n;

    int *sol=new int[n];

    for(int i=0;i<n;i++){

      cin >> sol[i];

    }

    sort(sol,sol+n);

    long long value = abs(1ll*sol[0]+sol[n-1]+sol[1]);

    a=sol[1];b=sol[n-1];c=sol[0];

    for(int i=0;i<n-2;i++){

      start=i+1;

      end=n-1;

      while(start<end){

          long long tmp = 1ll*sol[start]+sol[end]+sol[i];

          if(value > abs(tmp)){

            value=abs(tmp);

            a=sol[start];b=sol[end];c=sol[i]; 

         

          }

        if(tmp>0) end--;

        else start++;

      }

    }

    cout << c << " " << a << " " << b;

}