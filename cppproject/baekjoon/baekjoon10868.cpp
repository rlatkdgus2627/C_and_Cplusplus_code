#include <bits/stdc++.h>
#define INF (int)1e9+7

using namespace std;

int n,m;
int num[100001];
int segTree[400001];


int init(int s, int e, int node){
    if(s == e)  return segTree[node] = num[s];
    int mid = (s+e)/2;
    return segTree[node] = min(init(s,mid,node*2),init(mid+1,e,node*2+1));
}

int getMin(int s, int e, int node, int left, int right){
    if(left > e || right < s)   return INF;
    else if(left <= s && e <= right)    return segTree[node];
    int mid = (s+e)/2;
    return min(getMin(s,mid,node*2,left,right),getMin(mid+1,e,node*2+1,left,right));
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int x,y;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    init(1,n,1);
    for(int i=0;i<m;i++){
        cin >> x >> y;
        cout << getMin(1,n,1,x,y) << "\n";
    }
    return 0;
}