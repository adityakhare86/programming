#include <bits/stdc++.h>
using namespace std;

int arr[100005], seg[4 * 100005];

void build(int idx, int low, int high){
    if(low == high){
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int query(int idx, int low, int high, int l, int r){
    if(low > high)return 0;
    if(low == l && high == r)return seg[idx];

    int mid = (low + high)/2;
    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);
    return seg[idx] = left + right;
}

void update(int idx, int low, int high, int pos, int newVal){
    if(low == high)seg[idx] = newVal;
    else{
        int mid = (low + high)/2;
        if(pos<=mid)
            update(idx*2+1, low, mid, pos, newVal);
        else    
            update(idx*2+2, mid+1, high, pos, newVal);
        
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }
}

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++)cin >> arr[i];

    build(0, 0, n-1);
    
    int q; cin>>q;
    while(q--){
        int l, r;
        cin>> l>> r;
        cout<<query(0, 0, n-1, l, r);
    }
}