#include <bits/stdc++.h>

using namespace std;

int t;
int n, sum;

int main(){
    int x;
    scanf("%d",&t);
    while(t--){
        sum = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",&x);
            sum += x;
        }
        if(sum == n)    printf("0\n");
        else if(sum < n)    printf("1\n");
        else printf("%d\n", sum - n);
    }
    return 0;
}