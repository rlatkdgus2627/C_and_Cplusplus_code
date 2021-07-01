#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][3], n, amount;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> amount;
    dp[0][1] = amount;
    for(int i = 2; i <= n; i++){
        cin >> amount;
        dp[1][1] = dp[0][0] + amount;
        dp[1][2] = dp[0][1] + amount;
        dp[1][0] = max(dp[0][0],max(dp[0][1],dp[0][2]));
        dp[0][0] = dp[1][0]; dp[0][1] = dp[1][1]; dp[0][2] = dp[1][2];
    }
    cout << max(dp[0][0],max(dp[0][1],dp[0][2])) << "\n";
}