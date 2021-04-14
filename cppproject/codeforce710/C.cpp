#include <bits/stdc++.h>

using namespace std;

int t, n, m, MAX, temp, k;
char str1[21], str2[21];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",str1);
        scanf("%s",str2);
        n = strlen(str1);
        m = strlen(str2);
        MAX = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                k = 0;
                while(i + k < n && j + k < m && str1[i+k] == str2[j+k]){
                    k++;
                }
                MAX = max(MAX , k);
            }
        }
        printf("%d\n",n+m - 2*MAX);
    }
    return 0;
}