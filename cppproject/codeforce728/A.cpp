#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n % 2 == 0){
            for(int i = 0; i < n/2; i++){
                printf("%d ", 2*i+2);
                printf("%d ", 2*i+1);
            }
            printf("\n");
        }
        else if(n == 1){
            printf("1\n");
        }
        else if(n == 3){
            printf("3 1 2\n");
        }
        else{
            printf("3 1 2 ");
            for(int i = 2; i <= n/2 ; i++){
                printf("%d ", 2*i+1);
                printf("%d ", 2*i);
            }
            printf("\n");
        }
    }
    return 0;
}