#include <bits/stdc++.h>

using namespace std;

long long p,l,v,ans;

int main(){
    int i = 1;
    while(i){
        cin >> l >> p >> v;
        if(!l&&!p&&!v)  break;
        ans = (v/p)*l;
        ans += min(l,v%p);
        cout << "Case "<< i <<": "<< ans << "\n";
        i++;
    }
    
    return 0;
}