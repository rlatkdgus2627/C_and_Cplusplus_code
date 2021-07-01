#include <bits/stdc++.h>

using namespace std;

int t,n,k;

long long num[32];
long long dist[32];
long long ans,MAX;
double answer;

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <=t; tc++){
        scanf("%d %lld",&n,&k);
        memset(num,0,sizeof(num));
        memset(num,0,sizeof(dist));
        for(int i = 0; i < n; i++){
            scanf("%lld",&num[i]);
        }
        sort(num,num+n);
        dist[0] = num[0]-1;
        dist[n] = k - num[n-1];
        for(int i = 1; i <= n - 1; i++){
            dist[i] = (num[i] - num[i-1])/2;
            MAX = (num[i] - num[i-1] - 1, MAX);
        }
        sort(dist,dist+n+1);
        ans = max(MAX, dist[n] + dist[n-1]);

        answer = (double)ans/(double)k;
        printf("Case #%d: %lf\n",tc, answer);
    }
}