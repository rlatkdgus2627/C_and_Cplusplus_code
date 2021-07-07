#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        int x,cnt = 0;
        cin >> n;
        for(int i = 0; i < 2*n; i++){
            cin >> x;
            if(x%2 == 1){
                cnt++;
            }
        }
        if(cnt == n){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
    return 0;
}