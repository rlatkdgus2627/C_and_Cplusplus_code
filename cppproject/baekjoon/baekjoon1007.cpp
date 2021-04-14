#include <bits/stdc++.h>

using namespace std;

long long xsum, ysum;

int t,n;
long long dot[21][2];

long long solve(int k,int cur,long long curx, long long cury){
    if(k == n/2){
        return (xsum - 2*curx)*(xsum - 2*curx)+(ysum - 2*cury)*(ysum - 2*cury);
    }
    long long ret = 0x7fffffffffffffffL;

    for(int i = cur+1; i < n; i++){
        ret = min(ret, solve(k+1,i,curx+dot[i][0],cury+dot[i][1]));
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        xsum = ysum = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> dot[i][0] >> dot[i][1];
            xsum += dot[i][0];
            ysum += dot[i][1];
        }
        cout.precision(16);
        cout << sqrt(solve(0,-1,0,0)) << "\n";
    }
    return 0;
}

