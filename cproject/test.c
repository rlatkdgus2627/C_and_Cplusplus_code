#include <stdio.h>

int main(){
    unsigned int a;
    int input;
    scanf("%d",&input);
    for(int i = 15; i>= 0; i--){
        printf("%d",(input & (1 << i)) == 0 ? 0 : 1);
    }
    return 0;
}
