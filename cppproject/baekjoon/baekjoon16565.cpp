#include <bits/stdc++.h>

using namespace std;

long long c[53][53];

long long ans;

int n;

int main(){
    cin >> n;
    c[0][0] = 1;
    for(int i = 1; i <= 52; i++){
        c[i][0] = 1;    
        c[i][i] = 1;
        for(int j = 1; j <= i-1; j++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%10007;
        }
    }

    for(int i = 1; i <= n/4; i++){
        if(i % 2 == 1){
            ans += c[52 - 4*i][n - 4*i]* c[13][i];
        }
        else{
            ans -= c[52 - 4*i][n - 4*i] * c[13][i];
        }
        ans %= 10007;
    }
    if(ans < 0) ans += 10007;
    cout << ans;
    return 0;
}