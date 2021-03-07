#include <bits/stdc++.h>

int n;
int num[10];
int ans;
bool check[10];


void solve(int p, int prev, int cnt){
    if(p == n){
        if(cnt > ans)   ans = cnt;  
    }

    for(int i=0;i<n;i++){
        if(!check[i]){
            check[i] = true;
            solve(p+1,i,cnt+labs(num[i] - num[prev]));
            check[i] = false;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++){
        check[i] = true;
        solve(1,i,0);
        check[i] = false;
    }
    printf("%d",ans);
    return 0;
}