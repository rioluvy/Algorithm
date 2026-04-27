#include <iostream>

#include <algorithm>

#include <vector>

#define endl "\n"

using namespace std;

int main() {

    int n, a, b, x;

    cin >> n;

    for(int i=0;i<n;i++){

      cin >> a >> b >> x;

      x--;

      cout << (a*x + b) << endl;

    }

    

	return 0;   }