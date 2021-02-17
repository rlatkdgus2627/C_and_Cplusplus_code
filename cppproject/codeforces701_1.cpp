#include <bits/stdc++.h>

using namespace std;

int t,a,b,ans,inc,temp,check;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> a >> b;
        ans = 1e9;
        inc = 0;
        if(a<b){
            cout << "1" << "\n";
            continue;
        }
        while(1){
            temp = a;
            check = 0;
            if(b == 1){
                b++;
                inc++;
                continue;
            }
            while(temp){
                temp/=b;
                check++;
            }
            if(ans >= check + inc){
                ans = check + inc;
                b++;
                inc++;
            }
            else{
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}