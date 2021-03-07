#include <bits/stdc++.h>

using namespace std;

int n,m;
int board[12][12];

int dp[11][11][1<<11];

int solve(int row, int col, int cur){
    if(row > n || col > m)  return 0;

    int& ret = dp[row][col][cur];

    if(ret != 0)    return ret;

    

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    cin.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
        cin.clear();
    }
    return 0;
}