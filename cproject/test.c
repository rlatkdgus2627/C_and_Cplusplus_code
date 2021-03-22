#include <stdio.h>

int main(){
    int a, b, n;
    int num[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        num[i] = a+b;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",num[i]);
    }
    return 0;
}