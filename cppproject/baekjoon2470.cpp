#include <bits/stdc++.h>

using namespace std;

int n, x, ans;
int number[100001];
int ans1, ans2, diff = 0x7fffffff;

int ABS(int a){
    if(a<0)   return -1*a;
    else return a;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> number[i];
    }
    sort(number,number+n);
    
    int a = 0, b = n-1;

    while(a < b){
        if(number[a]+number[b]>0){
            if(ABS(number[a]+number[b]) < diff){
                diff = ABS(number[a]+number[b]);
                ans1 = number[a];
                ans2 = number[b];
            }
            b--;
        }
        else if(number[a]+number[b]<0){
            if(ABS(number[a]+number[b]) < diff){
                diff = ABS(number[a]+number[b]);
                ans1 = number[a];
                ans2 = number[b];
            }
            a++;
        }
        else{
            ans1 = number[a];
            ans2 = number[b];
            break;
        }
    }

    cout << ans1 << " " << ans2;
    return 0;
}