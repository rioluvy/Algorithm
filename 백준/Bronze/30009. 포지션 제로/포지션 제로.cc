#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

#include <cstdlib>

#define endl "\n"

using namespace std;

int main() {

    int n, x, y, r, line, diff;

    cin >> n;

    cin >> x >> y >> r;

    int a=0, b=0;

    for(int i=0; i<n; i++){

      cin >> line;

      diff = abs(x-line);

      if (diff==r) a++;

      else if(line>x-r && line<x+r) b++;

    }

    cout << b << " " << a;

    

	return 0;   }