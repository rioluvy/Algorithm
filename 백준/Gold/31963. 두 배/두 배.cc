#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll n, a, b, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    double* arr = new double[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    a = 0;
    for(int i = 1; i < n; i++){
        b = (ceil(log2(arr[i-1]/arr[i])) + a);
        b = max(b,(ll)0);
        ans += b;
        a = b;
    }
    cout << ans;
}