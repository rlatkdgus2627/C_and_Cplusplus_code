#include <bits/stdc++.h>

using namespace std;

long long ans[10], n;

long long point(int exp){
    long long ret = 1;
    for(int i = 0; i < exp; i++){
        ret *= 10LL;
    }
    return ret;
}

void solve(long long num, int ten){
    long long cnt, p;
    long long mul = point(ten);
    
    if(num == 0){
        return;
    }
    
    while(num%10 < 9){
        num++;
        p = num;
        while(p>0){
            ans[p%10]-=mul;
            p/=10;
        }
    }

    cnt = (num/10)+1;

    for(int i = 0 ; i < 10; i++){
        if(i == 0)  ans[i] += mul*(cnt-1);
        else ans[i] += mul*cnt;
    }

    solve(num/10,ten+1);
    return;
}

int main(){
    cin >> n;
    solve(n,0);
    for(int i = 0; i < 10; i++){
        cout << ans[i] << " ";
    }
    return 0;
}