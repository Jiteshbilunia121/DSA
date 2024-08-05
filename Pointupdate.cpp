#include<bits/stdc++.h>
using namespace std;

class NumArray {
vector<int> a;
int n;
int seg[12*10000];

public:
    void buildTree(int lo, int hi, int idx){
            //base case
            if(lo == hi){
                seg[idx] = a[lo];
                return;
            }
            int mid = (lo+hi)/2;
            buildTree(lo, mid, 2*idx+1);
            buildTree(mid+1, hi, 2*idx+2);
            seg[idx] = seg[2*idx+2]+seg[2*idx+1];
            return;
    }

// time complexity of Range sum (l, r) = O(logN)
public:
    int query(int l, int r, int lo, int hi, int idx){
        // check if (lo, hi) lies completely inside (l, r)
        if(lo >= l && hi <= r){
            return seg[idx];
        }
        // lies outside completely
        if(lo > r || hi < l){
            return 0;
        }
        // lies partially
        int mid = (lo+hi)/2;
        int left = query(l, r, lo, mid, 2*idx+1);
        int right = query(l, r, mid+1, hi, 2*idx+2);
        return (left+right);
    }
// time complexity of pointupdate == O(logN)
public: 
    void pointupdate(int node, int idx, int lo, int hi, int val){
        if(lo == hi){
            a[node] = val;
            seg[idx] = val;
            return;
        }
        int mid = (lo+hi)/2;
        // check if node lies to left or right
        if(node >= lo && node <= mid)
            pointupdate(node, 2*idx+1, lo, mid, val);
        if(node > mid && node <= hi)
            pointupdate(node, 2*idx+2, mid+1, hi, val);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        a = nums;
        buildTree(0, n-1, 0);
    }
    
    void update(int index, int val) {
        pointupdate(index, 0, 0, n-1, val);
        
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, n-1, 0);
        
    }
    void printArry(){
        for(auto i : a){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
};


int main(){

    vector<int> nums{1, 3, 0, 3, 2, 4, 5};
    NumArray* obj = new NumArray(nums);
    obj->update(2, 2);
    obj->printArry();
    cout << obj->sumRange(2, 4);
    return 0;
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */