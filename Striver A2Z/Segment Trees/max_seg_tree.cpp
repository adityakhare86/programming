#include <bits/stdc++.h>
using namespace std;

//declare the DS globally
//the maximum space that a seg tree takes = 4 * N;

//the seg tree we have built is to find the maximum in a given range
int arr[100005], seg[4 * 100005];

void build(int idx, int low, int high){
    if(low == high){                //base when i.e. when we reach the root nodes
        seg[idx] = arr[low];
        return;
    }
    
    int mid = (low + high)/2;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);

    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]); // for non-leaf nodes
}

/*
There three conditions on how we query the seg tree:
1) The query completely lies within the current query -> return node valoue
2) The query completely lies outside the current query -> return INT_MIN
3) The query overlaps with the current query -> further query the seg tree until we find (1) or (2)
*/
int query(int idx, int low, int high, int l, int r){
    if(l>=low && high<=r)return seg[idx];
    if(low > high)return INT_MIN;

    int mid = (low + high)/2;
    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);
    return max(left, right);
}

void update(int idx, int low, int high, int pos, int newVal){
    if(low == high)seg[idx] = newVal;
    else{
        int mid = (low + high)/2;
        if(pos <= mid)
            update(idx*2+1, low, mid, pos, newVal);
        else   
            update(idx*2+2, mid+1, high, pos, newVal);
        seg[idx] = max(seg[idx*2+1], seg[idx*2+2]);
    }
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];

    build(0, 0, n-1); //index of root, low, high

    //computing queries
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>> l>> r;
        cout<<query(0, 0, n-1, l, r);
    }
}