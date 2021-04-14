#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int t, n, k;
int num[100001];
int maxTree[400001], minTree[400001];

int maxinit(int s,int e,int node){
    if(s == e)  return maxTree[node] = num[s];
    int mid = (s+e)/2;
    return maxTree[node] = max(maxinit(s,mid,node*2),maxinit(mid+1,e,node*2+1));
}

int mininit(int s,int e,int node){
    if(s == e)  return minTree[node] = num[s];
    int mid = (s+e)/2;
    return minTree[node] = min(mininit(s,mid,node*2),mininit(mid+1,e,node*2+1));
}

int maxupdate(int s, int e, int node, int index, int value){
    if (index < s || e < index) return maxTree[node];
    if (s == e) return maxTree[node] = value;
    int mid = (s + e) / 2;
    return maxTree[node]=max(maxupdate(s,mid,node*2,index,value), maxupdate(mid+1,e,node*2+1,index,value));
}

int minupdate(int s, int e, int node, int index, int value){
    if (index < s || e < index) return minTree[node];
    if (s == e) return minTree[node] = value;
    int mid = (s + e) / 2;
    return minTree[node]=min(minupdate(s,mid,node*2,index,value), minupdate(mid+1,e,node*2+1,index,value));
}

int getmax(int s, int e, int node, int l, int r){
    if(r < s || e < l)  return -1;
    else if(l <= s && e <= r)    return maxTree[node];
    int mid = (s + e) / 2;
    return max(getmax(s, mid, node*2, l, r),getmax(mid+1, e, node*2+1, l, r));
}

int getmin(int s, int e, int node, int l, int r){
    if(r < s || e < l)  return INF;
    else if(l <= s && e <= r)    return minTree[node];
    int mid = (s + e) / 2;
    return min(getmin(s, mid, node*2, l, r),getmin(mid+1, e, node*2+1, l, r));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    int a, b, c, temp;
    while(t--) {
        cin >> n >> k;
        for(int i=0;i<n;i++){
            num[i] = i;
        }
        maxinit(0,n-1,1);
        mininit(0,n-1,1);
        /*
        cout << getmin(0,n-1,1,1,2) << endl;
        cout << getmax(0,n-1,1,1,2) << endl;
        */
        for(int i = 0 ; i < k; i++){
            cin >> a >> b >> c;
            if(a == 0){
                maxupdate(0,n-1,1,b,num[c]);
                maxupdate(0,n-1,1,c,num[b]);
                minupdate(0,n-1,1,b,num[c]);
                minupdate(0,n-1,1,c,num[b]);
                temp = num[b];
                num[b] = num[c];
                num[c] = temp;
            }
            else{
                if(b == getmin(0,n-1,1,b,c) && c == getmax(0,n-1,1,b,c))  cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }

    return 0;
}