#include <bits/stdc++.h>

using namespace std;

long long n, board[33][33], dp[33][33][3];

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
    
    dp[1][2][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(board[i][j]) continue;
            if(!board[i-1][j]&&!board[i][j-1]&&!board[i-1][j-1]){
                dp[i][j][1] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
            if(!board[i][j-1]){
                dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][1];
            }
            if(!board[i-1][j]){
                dp[i][j][2] += dp[i-1][j][1] + dp[i-1][j][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";
    return 0;
}