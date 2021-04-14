#include <bits/stdc++.h>

using namespace std;

int t, n, x, temp, cnt, MAX;
int num[200001];

int main(){
    scanf("%d",&t);
    while(t--){
        
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
           scanf("%d",&num[i]);
        }
        MAX = 0;
        sort(num,num+n);
        temp = num[0];
        cnt = 1;
        for(int i = 1; i < n; i++){
           if(num[i] == temp){
               cnt++;
           }
           else{
               MAX = max(MAX,cnt);
               temp = num[i];
               cnt = 1;
           }
        }
        MAX = max(MAX,cnt);
        printf("%d\n",max(n%2, 2*MAX - n));
    }
    return 0;
}