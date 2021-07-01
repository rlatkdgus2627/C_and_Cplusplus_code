#include <bits/stdc++.h>

using namespace std;

int n, k;
char input[500001];
string str, makestr;
char first;
int cutindex;
bool check;

int main(){
    
    scanf("%d %d",&n,&k);
    scanf("%s",input);
    str = input;
    if(n == 1){
        for(int i = 0; i < k; i++){
            printf("%c", input[0]);
        }
    }
    first = str[0];
    cutindex = n;
    for(int i = 1; i < n; i++){
        if(str[i] > first){
            cutindex = i;
            break;
        }
        else if(str[i] == first){
            check = false;
            for(int j = i; j < n; j++){
                if(str[j] < str[i]){
                    check = true; 
                    break;
                }
            }
            if(!check)   cutindex = i;
        }
    }
    str = str.substr(0,cutindex);
    makestr = "";
    while(makestr.length() < k){
        makestr = makestr + str;
    }
    for(int i = 0; i < k; i++){
        printf("%c",makestr[i]);
    }
    
    return 0;
}