#include <bits/stdc++.h>

#define INF 1000000001

using namespace std;

int n, work[20][20];

int dp[20][1<<20];

int solve(int cur, int set){
    if(cur == n)   return 0;

    int& ret = dp[cur][set];

    if(ret != -1){
        return ret;
    }
    ret = INF;

    for(int i=0;i<n;i++){
        if(set & (1 << i))  continue;
        ret = min(ret, work[cur][i] + solve(cur+1,set | (1 << i)));
    }

    return ret;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> work[i][j];
        }
    }
    cout << solve(0,0) << "\n";

    return 0;
}