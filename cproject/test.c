#include <stdio.h>

int main(){
    int max, min, sum = 0;
    int num[10];

    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
    }

    max = min = num[0];

    for(int i=0;i<10;i++){
        if(num[i] > max){
            max = num[i];
        }
        if(min > num[i]){
            min = num[i];
        }
        sum += num[i];
    }
    printf("max:%d min:%d avg:%lf", max, min, sum/10.0);
    return 0;
}