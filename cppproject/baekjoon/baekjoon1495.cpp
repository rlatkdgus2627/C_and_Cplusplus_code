#include <iostream>

using namespace std;

int n,s,m,maxVolume = -1;
int volume[101];

bool dp[101][1001];

bool safe(int num){
    return (0<=num&&num<=m);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> s >> m;
    for(int i=0;i<n;i++){
        cin >> volume[i];
    }
    dp[0][s] = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]&&safe(j+volume[i]))    dp[i+1][j+volume[i]] = true;
            if(dp[i][j]&&safe(j-volume[i]))    dp[i+1][j-volume[i]] = true;
        }
    }
    for(int i=0;i<=m;i++){
        if(dp[n][i])   maxVolume = i;
    }
    cout << maxVolume << "\n";
    return 0;
}