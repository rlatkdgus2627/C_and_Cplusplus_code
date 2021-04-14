#include <bits/stdc++.h>
#define MAX (int)1e9

using namespace std;

int t,n,ans,x,y;
char str[1001];

int dp[1001][2];

int solve(int cur, int prev){
    if(cur == n)    return 0;
    int& ret = dp[cur][prev];
    if(ret != MAX)  return ret;

    if(str[cur] == 'C'){
        if(prev == 1) ret = solve(cur+1,0)+y;
        else ret = solve(cur+1,0);
    }
    else if(str[cur] == 'J'){
        if(prev == 0) ret = solve(cur+1,1)+x;
        else ret = solve(cur+1,1);
    }
    else{
        if(prev == 0){
            ret = solve(cur+1,0);
            ret = min(ret, solve(cur+1,1)+x);
        }
        else{
            ret = solve(cur+1,1);
            ret = min(ret, solve(cur+1,0)+y);
        }
    }
    return ret;
}

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        ans = 0;
        scanf("%d %d %s",&x, &y, str);
        n = strlen(str);

        for(int i=0;i<n+1;i++){
            dp[i][0] = dp[i][1] = MAX;
        }

        if(str[0] == 'C')   ans = solve(1,0);
        else if(str[0] == 'J')  ans = solve(1,1);
        else ans = min(solve(1,0),solve(1,1));

        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}