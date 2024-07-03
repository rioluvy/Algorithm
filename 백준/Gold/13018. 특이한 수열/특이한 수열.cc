#include <iostream>
using namespace std;
int main() {
    int n, k;cin >> n >> k;
    if(n == k){cout << "Impossible";return 0;}
    k = n-k;cout << k << " ";
    for(int i = 1; i < k; i++)cout << i << " ";
    k = n-k;
    for(int i = 1; i <= k; i++)cout << i+n-k << " ";
}