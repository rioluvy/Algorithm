#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#define endl "\n"
#define ll long long
#define prime 1000000007
using namespace std;
int n,m,k,height,tree_size;
vector<ll> arr;
vector<ll> tree_arr;
vector<tuple<int,int,ll>> info;

ll make_segment_tree(int node, int start, int end){
    if(start == end) return tree_arr[node] = arr[start];
    int mid = (start+end)/2;
    ll left = make_segment_tree(node*2,start,mid);
    ll right = make_segment_tree(node*2+1,mid+1,end);
    tree_arr[node] = (left * right)%prime;

    return tree_arr[node];
}
ll pro(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && right >= end) return tree_arr[node];

    int mid = (start+end)/2;
    ll left_part = pro(node*2,start,mid,left,right);
    ll right_part = pro(node*2+1,mid+1,end,left,right);
    return (left_part * right_part)%prime;
}
ll update_segment_tree(int node,int start,int end,int idx,ll change){
    if(idx < start || idx > end) return tree_arr[node];
    if(start == end) return tree_arr[node] = change;
    if(start!=end){
        int mid = (start+end)/2;
        ll left = update_segment_tree(node*2,start,mid,idx,change);
        ll right = update_segment_tree(node*2+1,mid+1,end,idx,change);
        ll parent = (left*right)%prime;
        return tree_arr[node] = parent;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int num,a,b,c;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0 ; i < m+k; i++){
        cin >> a >> b >> c;
        info.push_back({a,b,c});
    }
    height = (int)ceil(log2(n));
    tree_size = (1<<(height+1));
    tree_arr.resize(tree_size,1);
    make_segment_tree(1,0,n-1);

    for(int i = 0 ; i<m+k; i++){
        if(get<0>(info[i]) == 1){
            int idx = get<1>(info[i])-1;
            ll diff = get<2>(info[i]);
            update_segment_tree(1,0,n-1,idx,diff);
        }
        else{
            int left,right;
            left = get<1>(info[i])-1;
            right = get<2>(info[i])-1;
            cout <<pro(1,0,n-1,left,right)%prime << endl;
        }
    }
}