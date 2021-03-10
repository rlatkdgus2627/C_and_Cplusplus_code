#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long ll;

ll num[1000001], segtree[4000001];
ll n,m,k;

ll init(ll s, ll e, ll node){
    if(s == e)  return segtree[node] = num[s];
    ll mid = (s+e)/2;
    return segtree[node] = (init(s,mid,node*2) * init(mid+1,e,node*2+1))%mod;
}

ll getMul(ll s, ll e, ll node, ll left, ll right){
    if(left > e || right < s)    return 1;
    else if(left <= s && e <= right)    return segtree[node];
    ll mid = (s+e)/2;
    return (getMul(s,mid,node*2,left,right) * getMul(mid+1,e,node*2+1,left,right))%mod;
}

ll update(ll s, ll e, ll node, ll index, ll data){
    if(index < s || index > e)  return segtree[node];
    if(s == e)  return segtree[node] = data;
    ll mid = (s+e)/2;
    return segtree[node] = (update(s,mid,node*2,index,data) * update(mid+1,e,node*2+1,index,data))%mod;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    ll x,y,z;

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    init(0,n-1,1);
    for(int i=0;i<m+k;i++){
        cin >> x >> y >> z;
        if(x == 1){
            update(0,n-1,1,y-1,z);
        }
        else if(x == 2){
            cout << getMul(0,n-1,1,y-1,z-1) << "\n";
        }
    }
    return 0;
}