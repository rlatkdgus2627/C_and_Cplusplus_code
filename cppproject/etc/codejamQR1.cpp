#include <bits/stdc++.h>

int t,n,ans;
int num[101], save[101];

void reverse(int s, int e){
    ans += (e-s)+1;
    for(int i = s; i <= e; i++){
        save[i] = num[i];
    }
    for(int i = s; i <= e; i++){
        num[i] = save[s + e - i];
    }
}
int getminIndex(int s){
    int Min = num[s];
    int ret = s;
    for(int i=s+1;i<=n;i++){
        if(Min > num[i]){
            Min = num[i];
            ret = i; 
        }
    }
    return ret;
}

void solve(){
    ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=n-1;i++){
        reverse(i,getminIndex(i));
    }
}

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        solve();
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}