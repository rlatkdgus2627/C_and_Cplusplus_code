#include <bits/stdc++.h>

using namespace std;

long long dp[1001][1001][2];
long long num[1001];
int T, n;

long long solve(int l, int r, int s){
    if(l == r && s)  return 0;
    else if(l == r) return num[l];

    long long& ret = dp[l][r][s];
    if(ret) return ret;

    if(s) return ret = min(solve(l+1,r,0), solve(l,r-1,0));
    else return ret = max(solve(l+1,r,1) + num[l], solve(l,r-1,1) + num[r]);

    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }
        cout << solve(0, n-1, 0) << "\n";
    }
}