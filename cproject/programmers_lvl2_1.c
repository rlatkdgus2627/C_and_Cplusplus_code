#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    bool answer = true;
    int cnt=0;

    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(')   cnt++;
        else{
            cnt--;
            if(cnt < 0){
                answer = false;
                break;
            }
        }
    }

    if(cnt > 0) answer = false;

    return answer;
}

int main(){

    return 0;
}