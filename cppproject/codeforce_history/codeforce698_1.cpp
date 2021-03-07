#include <bits/stdc++.h>

using namespace std;

int t,n,num[101],cnt[101],ans;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)    cin >> num[i];
        for(int i=0;i<n;i++)    cnt[num[i]]++;
        for(int i=0;i<101;i++){
            if(cnt[i] > ans) ans = cnt[i];
        }
        cout << ans << "\n";
    }
    return 0;
}