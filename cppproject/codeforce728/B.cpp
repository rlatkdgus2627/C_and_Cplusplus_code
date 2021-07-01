#include <bits/stdc++.h>

using namespace std;

long long t, n;
long long ans;
long long num[200001];


int main(){
    scanf("%lld",&t);
    while(t--){
        ans = 0;
        scanf("%lld",&n);
        for(long long i = 1; i <= n; i++){
            scanf("%lld", &num[i]);
        }
        for(long long i = 1; i <= n-1; i++){
            long long j = num[i] - i;
            while(j <= n){
                if(j > i && num[i]*num[j] == i + j){
                    ans++;
                }
                j += num[i];
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}