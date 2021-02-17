#include <bits/stdc++.h>

using namespace std;

int t,x,y,q;

long long ans,temp;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> x >> y;
        if(x<=2 || y<=1){
            cout << "0" << "\n";
            continue;
        }
        while(1){
            q++;
            temp = min(x/q,y);

            if(temp <= 1){
                break;
            }

            
            for(int i=1;i<=q;i++){
                if(((i+1)*q) % i == 0){
                    temp--;
                }
            }
            ans += temp;
        }

        cout << ans << "\n";

    }

    return 0;
}
