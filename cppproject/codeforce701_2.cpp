#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n,q,k,l,r;
ll num[100002];
ll ans[100002];
ll psum[100002];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> q >> k;
    num[0] = 0;
    num[n+1] = k+1;
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    for(int i=1;i<=n;i++){
        ans[i] = num[i+1] - num[i-1] - 2;
    }
    for(int i=1;i<=n;i++){
        psum[i] = psum[i-1] + ans[i];
    }

    for(int i=0;i<q;i++){
        cin >> l >> r;
        if(l==r){
            cout << k-1 << "\n";
        }
        else cout << max(psum[r-1] - psum[l], 0LL) + num[l+1] - 2 + k - num[r-1] - 1<< "\n";
    }

    return 0;
}