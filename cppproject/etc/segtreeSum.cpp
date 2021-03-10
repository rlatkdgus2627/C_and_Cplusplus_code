#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m,k;
ll num[1000001];
ll segtree[4000004];

ll init(ll s, ll e, ll node){ // s,e는 배열의 범위 node는 세그먼트 트리의 node인덱스
    if(s == e)  return segtree[node] = num[s];
    ll mid = (s+e)/2;
    return segtree[node] = init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

ll getSum(ll s, ll e, ll node, ll left, ll right){ //left와 right은 구하고자 하는 범위
    if(left > e || right < s)   return 0;
    if(left <= s && e <= right) return segtree[node];
    ll mid = (s+e)/2;
    return getSum(s,mid,node*2,left,right)+getSum(mid+1,e,node*2+1,left,right);
}

void update(ll s, ll e, ll node, ll index, ll data){ //index에 있는 수를 diff만큼 바꾸기(data = 바꿀려는 수 - 기존의 수)
    if(index < s || e < index)  return;
    segtree[node] += data;
    if(s == e)  return;
    ll mid = (s+e)/2;
}

int main(){
    return 0;
}