#include <bits/stdc++.h>

using namespace std;

int n, m;
long long dp[1025][1025];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    long long temp;
    int x1,y1,x2,y2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> temp;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + temp;
        }
    }
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] + dp[x1-1][y1-1] - dp[x2][y1-1] - dp[x1-1][y2] << "\n";
    }
    return 0;
}