#include <bits/stdc++.h>
#define INF 1e9+7

using namespace std;

int num[100001];
int minSegtree[400004];
int maxSegtree[400004];
int n,m;

int initMin(int s, int e, int node){
    if(s == e)  return minSegtree[node] = num[s];
    int mid = (s+e)/2;
    return minSegtree[node] = min(initMin(s,mid,node*2),initMin(mid+1,e,node*2+1));
}

int initMax(int s, int e, int node){
    if(s == e)  return maxSegtree[node] = num[s];
    int mid = (s+e)/2;
    return maxSegtree[node] = max(initMax(s,mid,node*2),initMax(mid+1,e,node*2+1));
}

int getMin(int s,int e,int node,int left, int right){
    if(left > e || right < s)   return INF;
    else if(left <= s && e <= right)    return minSegtree[node];
    int mid = (s+e)/2;
    return min(getMin(s,mid,node*2,left,right),getMin(mid+1,e,node*2+1,left,right));
}

int getMax(int s,int e,int node,int left, int right){
    if(left > e || right < s)   return -1;
    else if(left <= s && e <= right)    return maxSegtree[node];
    int mid = (s+e)/2;
    return max(getMax(s,mid,node*2,left,right),getMax(mid+1,e,node*2+1,left,right));
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int x,y;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    initMin(0,n-1,1);
    initMax(0,n-1,1);
    for(int i=0;i<m;i++){
        cin >> x >> y;
        cout << getMin(0,n-1,1,x-1,y-1) << " " << getMax(0,n-1,1,x-1,y-1) << "\n";
    }
    return 0;
}