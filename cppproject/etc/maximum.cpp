#include <bits/stdc++.h>

using namespace std;

int n, ans = -1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int temp = 0, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        temp = max(temp,0) + x;
        ans = max(temp, ans);
    }
    cout << ans;
    return 0;
}