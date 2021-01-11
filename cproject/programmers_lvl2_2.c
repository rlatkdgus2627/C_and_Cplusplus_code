#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int w, int h) {
    long long answer = 0;
    long long temp;
    for(int i=1;i<=w;i++){
        temp = ((double)h/w)*(-1)*(i)+h;
        answer+=temp;
    }
    return answe*2LL;
}

int main(){
    return 0;
}