#include <bits/stdc++.h>

const long long MOD = 1e9+7;

using namespace std;

int t;
long long n;

long long solve(long long x){
    if(x == 0)  return 1;
    if(x == 1)  return 2;
    
    else if(x%2 == 0)   return ((solve(x/2)%MOD) * (solve(x/2)%MOD))%MOD;
    else return ((solve(x/2)%MOD) * (solve(x/2)%MOD) * 2)%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cout << "1" << "\n";
        }
        else{
            cout << solve(n-2) << "\n";
        }
    }
    return 0;
}