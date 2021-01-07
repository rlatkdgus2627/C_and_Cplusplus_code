#include <cstdio>

using namespace std;

int T;

int solve(int a,int b){
    if(b==0) return a;
    else return solve(b,a%b);
}

int main(){
    scanf("%d",&T);
    while(T--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",x*y/solve(x,y));
    }
    return 0;
}