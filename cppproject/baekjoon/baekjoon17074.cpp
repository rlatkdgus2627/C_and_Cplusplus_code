#include <bits/stdc++.h>

using namespace std;

int n, ans = 2;
long long x, y;
long long num[100001];
bool check, check2;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> num[i];
    }
    num[0] = (long long)-1e9;
    for(int i = 2; i <= n; i++){
        if(num[i] < num[i-1] && check){
            check2 = true;
            break;
        }
        else if(num[i] < num[i-1]){
            x = i-1;
            y = i;
            check = true;
        }
    }

    if(check2)  cout << "0";  
    else if(check){
        for(int i=2;i<=n;i++){
            if(i == x){
                continue;
            }
            if(i-1 == x && num[i-2] > num[i]){
                ans--;
                break;
            }
            else if(i-1 != x && num[i-1] > num[i]){
                ans--;
                break;
            }
        }
        for(int i=2;i<=n;i++){
            if(i == y){
                continue;
            }
            if(i-1 == y && num[i-2] > num[i]){
                ans--;
                break;
            }
            else if(i-1 != y && num[i-1] > num[i]){
                ans--;
                break;
            }
        }
        cout << ans;
    }  
    else cout << n;
    
    return 0;
}