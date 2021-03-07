#include <bits/stdc++.h>

using namespace std;

int num[100001],psum[100001],n,m;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    psum[1] = num[0]; 
    for(int i=2;i<=n;i++){
        psum[i] = psum[i-1]+num[i-1];
    }
    int p,q;
    for(int i=0;i<m;i++){
        cin >> p >> q;
        cout << psum[q]-psum[p-1] << "\n";
    }
    return 0;
}