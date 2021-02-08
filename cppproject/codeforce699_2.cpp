#include <bits/stdc++.h>

using namespace std;

int t,n,k;
int h[100];
int ans;

int main(){
    bool check;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        check = false;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> h[i];
        }
        while(k--){
            int j=0;
            for(j=0;j<n-1;j++){
                if(h[j] < h[j+1]){
                    ans = j;
                    h[j]++;
                    break;
                }
            }
            if(j == n-1){
                check = true;
                break;
            }
        }
        if(check){
            cout << "-1" << "\n";
        }
        else cout << ans+1 << "\n";
    }
    return 0;
}