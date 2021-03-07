#include <bits/stdc++.h>

using namespace std;

int t,n,ans;
bool escape[101];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        memset(escape,false,sizeof(escape));
        ans = 0;

        cin >> n;

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                escape[j] = (escape[j] ? false : true);
            }
        }

        for(int i=1;i<=n;i++){
            ans += escape[i];
        }

        cout << ans << "\n";
    }
}