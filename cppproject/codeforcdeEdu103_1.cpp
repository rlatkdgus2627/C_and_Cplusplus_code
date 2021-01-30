#include <bits/stdc++.h>

using namespace std;

long long t,n,k;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n<=k){
            cout << (long long)ceil((double)k/n) << "\n";
        }
        else{
            if(n%k == 0) cout << "1" << "\n";
            else cout << "2" << "\n";
        }
    }

    return 0;
}