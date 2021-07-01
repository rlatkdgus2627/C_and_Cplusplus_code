#include <bits/stdc++.h>

using namespace std;

int k;
long long n, x, t;

int main(){
    scanf("%d", &k);
    while(k--){
        scanf("%lld %lld %lld", &n, &x, &t);
        if(t < x)   printf("0\n");
        else if(t == x) printf("%lld\n", n-1);
        else{
            long long temp = t/x;
            if(temp < n){

                printf("%lld\n", temp*(temp-1)/2 + temp*(n-temp));
            }
            else{
                printf("%lld\n", n*(n-1)/2);
            }
        }

    }
    return 0;
}