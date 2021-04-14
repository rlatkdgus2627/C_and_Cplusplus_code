#include <bits/stdc++.h>

using namespace std;

int t, n, c;
int ans[1001];

void solve(){
    int temp = c - n + 1, cur = 1, startpoint = 1, endpoint = n;
    int rev = 0;
    for(int i = n-1 ; >= 2 ; i--){
        rev++;
        if(temp < i){
            if(rev % 2 == 1){
                for(int j = startpoint; j < temp+1 ; j++){
                    ans[j] = (cur + temp + 1 - j);
                }
                for(int j = temp+1; j <= endpoint ; j++){
                    ans[j] = (cur + j);
                }
            }
            else{
                for(int j = startpoint; j < temp+1 ; j++){
                    ans[j] = (cur + );
                for(int j = temp+1; j <= endpoint ; j++){
                    ans[j] = cur;
                }
            }
            break;
        }
        else{
            if(rev % 2 == 1){
                ans[endpoint--] = cur;
            }
            else{
                ans[startpoint++] = cur;
            }
            cur++;
            temp -= i;
        }
    }
}

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d",&n,&c);
        if(!(n - 1 <= c && c <= (n*(n+1)/2-1))){
            printf("Case #%d: IMPOSSIBLE\n",tc);
            continue;
        }

        printf("Case #%d: ",tc);
        for(int i = 1; i <= n; i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}