#include <bits/stdc++.h>

using namespace std;

int t;
long long n,m,x;
long long r,c;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&m,&x);
        c = ceil((double)x/n); r = x % n; 
        printf("%lld\n", (r == 0 ? n-1 : r-1)*m + c);
    }
    return 0;
}