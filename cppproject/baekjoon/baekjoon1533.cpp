#include <bits/stdc++.h>

using namespace std;

map<pair<int, long long>, long long> dp;

int n, s, e;
long long t;

long long path[11][11];

long long solve(int cur, long long cost){
    if(cost > t){
        return 0;
    }
    if(cur == e && cost == t){
        return 1LL;
    }
    auto it = dp.find(make_pair(cur,cost));
    if(dp.end() != it){
        return it->second;
    }

    long long ret = 0LL;

    for(int i = 1; i <= n; i++){
        if(path[cur][i] != 0)   ret += solve(i, cost+path[cur][i]) % 1000003;
    }

    dp[make_pair(cur,cost)] = ret % 1000003;
    return ret;
}

int main(){
    scanf("%d %d %d %lld",&n, &s, &e, &t);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%1d",&path[i][j]);
            if(path[i][j] > 5)  path[i][j] = 0;
        }
    }
    cout << solve(s,0);
    return 0;
}