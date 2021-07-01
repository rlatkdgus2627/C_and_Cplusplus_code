#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int num[200001];
int mindiff, minindex;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d",num+i);
        }
        sort(num, num+n);
        if(n == 2){
            for(int i = 0; i < n; i++){
                printf("%d ",num[i]);
            }
            printf("\n");
            continue;
        }
        mindiff = num[1] - num[0];
        minindex = 0;
        for(int i = 1; i < n-1; i++){
            if(mindiff > num[i+1] - num[i]){
                mindiff = num[i+1] - num[i];
                minindex = i;
            }
        }
        for(int i = minindex+1; i < n; i++){
            printf("%d ",num[i]);
        }
        for(int i = 0; i <= minindex; i++){
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    return 0;
}1