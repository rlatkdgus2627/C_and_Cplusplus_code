#include <bits/stdc++.h>

using namespace std;

int t, n;

long long d[100001];
long long ans, temp;

int main(){
    scanf("%d",&t);
    while(t--){
        ans = 0;
        temp = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%lld",&d[i]);
        }
        sort(d, d+n);

        for(int i = 2; i < n; i++){
            ans -= (d[i]*(i-1) - temp);
            temp += d[i-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}