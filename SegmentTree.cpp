#include<bits/stdc++.h>
#include<inttypes.h>
using namespace std;
vector<int> a(100005);
int seg[4*100005];
/*
    Here segment tree nodes are storing maximum in that range
    seg[i](lo, hi) = max(arr[lo]...arr[hi])

*/
void build(int lo, int hi, int idx){
    // Leaf node will return the same value as the array
    if(lo == hi){
        seg[idx] = a[lo];
        return;
    }
    int mid = (lo+hi)/2;
    build(lo, mid, 2*idx+1);
    build(mid+1, hi, 2*idx+2);
    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    return;    
}

int query(int idx, int lo, int hi, int l, int r){
    // check if node lies completely in l & r
    // Hence this node of Tree will contribute to out answer
    if(lo >= l && hi <= r){
        return seg[idx];
    }
    // if node lies outside of(l, r)
    // This node will not contribute , so return INT_MIN
    if(lo > r || hi < l){
        return INT_MIN;
    }
    // If node lies partially we will check for left and right , and will return max of left and right Tree
    int mid = (lo+hi)/2;
    int left = query(2*idx+1, lo, mid, l, r);
    int right = query(2*idx+2, mid+1, hi, l, r);

    return max(left, right);
}

void printTree(int n){

    for(int i = 0; i < 4*n; ++i)
        cout << seg[i] << " ";
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n ; ++i){
        cin >> a[i];
    }   

    build(0, n-1, 0);
    int q, L, R;
    cout <<  "Enter the number of queries" << endl;
    cin >> q;
    while(q-- > 0){
        cin >> L >> R;
        cout << "Maximum in the range L to R - " << query(0, 0, n-1, L, R) << endl;
    }
    

    return 0;
}