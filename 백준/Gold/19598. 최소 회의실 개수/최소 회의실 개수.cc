#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pii> room;
    int n;
    ll a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        room.push_back({a,b});
    }
    sort(room.begin(),room.end());
    for(int i = 0; i < n; i++){
        if(pq.empty()) {
            pq.push(room[i].second);
            continue;
        }
        if(pq.size() > 0 && pq.top() <= room[i].first) pq.pop();
        pq.push(room[i].second);
    }
    cout << pq.size();
}