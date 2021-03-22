#include <bits/stdc++.h>

using namespace std;

int t,n,s,dc,c,Max;
int num[100001];
bool check, check2, check3;

int main(){
    scanf("%d",&t);
    while(t--){
        check = check2 = check3 = false;
        Max = dc = c = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            if(num[i] > Max){
                Max = num[i];
            }
        }

        if(n == 1){
            printf("0\n");
            continue;
        }

        s = num[1];
        for(int i=2;i<=n;i++){
            if(num[i]-num[i-1] < 0 && !check2){
                dc = num[i]-num[i-1];
                check2 = true;
                if(check3 && c + labs(dc) <= Max){
                    check = true;
                    break;
                }
            }
            else if(num[i]-num[i-1] < 0 && num[i]-num[i-1] != dc){
                check = true;
                break;
            }
            if(num[i]-num[i-1] >= 0 && !check3){
                c = num[i]-num[i-1];
                check3 = true;
                if(check2 && c + labs(dc) <= Max){
                    check = true;
                    break;
                }
            }
            else if(num[i]-num[i-1] >= 0 && num[i]-num[i-1] != c){
                check = true;
                break;
            }
        }
        if(check){
            printf("-1\n");
        }
        else if((dc == 0 || c == 0) && !check){
            printf("0\n");
        }
        else{
            printf("%d %d\n",labs(dc) + c, c);
        }
    }
    return 0;
}