#include <cstdio>
#include <cstring>
#include <algorithm>

int dp[101][101][101];

int solve(int a,int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    if(a>20||b>20||c>20){
        return solve(20,20,20);
    }
    int& ret = dp[a][b][c];
    if(ret) return ret;
    if(a<b && b<c){
        ret = solve(a,b,c-1)+solve(a,b-1,c-1)-solve(a,b-1,c);
    }
    else{
        ret = solve(a-1,b,c)+solve(a-1,b-1,c)+solve(a-1,b,c-1)-solve(a-1,b-1,c-1);
    }
    return ret;
}

int main(){
    int x=0,y=0,z=0;
    while(1){
        scanf("%d %d %d",&x,&y,&z);
        if(x==-1&&y==-1&&z==-1) break;
        printf("w(%d, %d, %d) = %d\n",x,y,z,solve(x,y,z));
    }
    return 0;
}