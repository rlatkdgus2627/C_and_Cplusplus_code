#include <bits/stdc++.h>

using namespace std;

int n;
long long top, bottom;
long long value[1001];
long long ans;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    cin >> top >> bottom;
    for(int i=0;i<n;i++){
        ans += (value[i]*bottom - top)*(value[i]*bottom - top);
    }
    cout << ans << "/" << bottom*bottom*(n-1) <<"\n";
    return 0;
}
