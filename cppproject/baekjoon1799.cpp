#include <cstdio>
#define FOR(x,n) for(int i=0;i<n;i++)

int n, ans;
int board[10][10];

int main(){
    scanf("%d",&n);
    FOR(i,n){
        FOR(j,n){
            scanf("%d",&board[i][j]);
        }
    }
    
}