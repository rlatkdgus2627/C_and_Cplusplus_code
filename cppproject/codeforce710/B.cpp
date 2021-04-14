#include <bits/stdc++.h>
#define INF 100000

using namespace std;

int t,n,k;

int dp[51][51];
char str[52];
int savefirst, savelast;

int solve(int i, int j){
    if(i - j > k)   return INF;
    if(i == savelast){
        return 1;
    }
    int& ret = dp[i][j];
    if(ret) return ret;
    if(str[i] == '*'){
        ret = solve(i+1,i)+1;
        if(i-j <= k-1){
            ret = min(ret , solve(i+1,j));
        }
    }
    else if(str[i] == '.'){
        ret = solve(i+1,j);
    }

    return ret;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        memset(dp,0,sizeof(dp));
        scanf("%s",str);
        savefirst = savelast = -1;
        for(int i = 0; str[i] != '\0';i++){
            if(str[i] == '*' && savefirst == -1){
                savefirst = savelast = i;
            }
            else if(str[i] == '*'){
                savelast = i;
            }
        }
        if(savefirst == -1) printf("0\n");
        else if(savefirst == savelast)  printf("1\n");
        else printf("%d\n",solve(savefirst+1, savefirst)+1);
    }
    return 0;
}