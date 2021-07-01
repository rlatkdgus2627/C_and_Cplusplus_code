#include <bits/stdc++.h>

using namespace std;

int n;
long long k, x, ans = 1;
vector<long long> level;
vector<long long> diff;

int main(){
    long long temp;
    scanf("%lld %lld %lld",&n,&k,&x);
    for(int i = 0; i < n; i++){
        scanf("%lld",&temp);
        level.push_back(temp);
    }
    sort(level.begin(),level.end());
    for(int i = 1; i < level.size(); i++){
        diff.push_back(level[i]-level[i-1]);
    }
    sort(diff.begin(), diff.end());
    for(long long cur : diff){
        if(cur <= x) continue;
        else{
            long long req = (cur % x == 0 ? (cur/x)-1 : cur/x);
            if(req <= k){
                k -= req;
            }
            else ans++;
        }
    }
    
    printf("%lld", ans);
    return 0;
}