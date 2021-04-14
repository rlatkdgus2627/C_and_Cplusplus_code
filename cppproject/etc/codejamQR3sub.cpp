#include <bits/stdc++.h>

using namespace std;

int t,n,c;
int ans[1001], temp[1001], num[1001], save[1001], cost;

bool check[1001];

void reverse(int s, int e){
    cost += (e-s)+1;
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

void calculate(){
    for(int i=1;i<=n-1;i++){
        reverse(i,getminIndex(i));
    }
}

void solve(int size){
    if(size == n){
        cost = 0;
        for(int i=1;i<=n;i++){
            num[i] = temp[i];
        }
        calculate();
        if(cost == c){
            for(int i=1;i<=n;i++){
                ans[i] = temp[i];
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            check[i] = true;
            temp[size+1] = i;
            solve(size+1);
            check[i] = false;
        }
    }
    return;
}

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d",&n,&c);
        if(!(n - 1 <= c && c <= (n*(n+1)/2-1))){
            printf("Case #%d: IMPOSSIBLE\n",tc);
            continue;
        }
        solve(0);
        printf("Case #%d: ",tc);
        for(int i = 1; i <= n; i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}