#include <bits/stdc++.h>

using namespace std;

int n, board[17][17],dp[17][17][3];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j] == -1)  continue;
            if(dp[i][j-1] != -1){
                dp[i][j] += dp[i][j-1];
            }
            if(dp[i-1][j] != -1){
                dp[i][j] += dp[i-1][j];
            }
            if(dp[i-1][j-1] != -1){
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    cout << dp[]
    return 0;
}