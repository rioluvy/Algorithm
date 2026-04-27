#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

using namespace std;

int main() {

	int n;    cin >> n;

    double arr[10001][2]={0,};

    for(int i=0;i<n;i++){

      cin >> arr[i][0] >> arr[i][1];

    }

    arr[n][0]=arr[0][0]; arr[n][1]=arr[0][1];

    double x_y=0,y_x=0;

    for(int i=0;i<n;i++){

      x_y += (arr[i][0]*arr[i+1][1]);

      y_x += (arr[i][1]*arr[i+1][0]);

    }

    double ans = abs(x_y-y_x)/2;

    cout << fixed;

    cout.precision(1);

    cout << (ans);

}