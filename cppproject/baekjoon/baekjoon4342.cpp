#include <bits/stdc++.h>

using namespace std;

long long n, m;

bool solve(long long a, long long b, bool ans){
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    if(a%b == 0)    return ans;
    else if(a/b == 1)   return solve(b, a%b, !ans);
    else return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        cout << (solve(n, m, 0) ? "B" : "A") << " wins" << "\n";
    }
    return 0;
}