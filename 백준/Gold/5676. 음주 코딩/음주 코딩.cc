#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;
vector<int> seq;
vector<int> Segtree;
int make_Segtree(int node, int start, int end){
    if(start == end){
        if(seq[start] > 0) return Segtree[node] = 1;
        else if(seq[start] < 0) return Segtree[node] = -1;
        else return Segtree[node] = 0;
    }
    int mid = (start+end)/2;
    int left = make_Segtree(node*2,start,mid);
    int right = make_Segtree(node*2+1,mid+1,end);
    return Segtree[node] = left*right;
}
int update_Segtree(int node, int start, int end, int idx, int change){
    if(idx < start || idx > end) return Segtree[node];
    if(start == end) return Segtree[node] = change;
    int mid = (start+end)/2;
    int left = update_Segtree(node*2,start,mid,idx,change);
    int right = update_Segtree(node*2+1,mid+1,end,idx,change);
    return Segtree[node] = left*right;
}
int query(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && right >= end) return Segtree[node];
    int mid = (start+end)/2;
    int left_part = query(node*2,start,mid,left,right);
    int right_part = query(node*2+1,mid+1,end,left,right);
    return (left_part * right_part);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, k, num;
    while(cin >> n >> k){
        for(int i = 0 ; i< n;i++){
            cin >> num;
            seq.push_back(num);
        }

        int height, tree_size;
        height = (int)ceil(log2(n));
        tree_size = (1<<(height+1));
        Segtree.resize(tree_size);
        make_Segtree(1,0,n-1);

        int idx, change, a, b;
        char com;
        for(int i = 0; i < k; i++ ){
            cin >> com;
            if(com == 'C'){
                cin >> idx >> change;
                seq[idx-1] = change;
                if (change < 0) update_Segtree(1,0,n-1,idx-1,-1);
                else if(change > 0) update_Segtree(1,0,n-1,idx-1,1);
                else update_Segtree(1,0,n-1,idx-1,0);
            }
            else{
                cin >> a >> b;
                int ans = query(1,0,n-1,a-1,b-1);
                if(ans==1) cout << '+';
                else if(ans==0) cout << '0';
                else cout << '-';
            }
        }
        cout << endl;
        Segtree.clear();
        seq.clear();
    }
}