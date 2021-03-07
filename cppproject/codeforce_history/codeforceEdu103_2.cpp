#include <bits/stdc++.h>

using namespace std;

int t,n;

long long chain[100001];

long long start[100001][2],ans;

long long temp1,temp2;

long long ABS(long long a, long long b){
    if(a-b<0) return -1LL*(a-b);
    else return (a-b);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> chain[i];
        }
        for(int i=0;i<n;i++){
            cin >> start[i][0];
        }
        for(int i=0;i<n;i++){
            cin >> start[i][1];
        }
        memset(dp,0,sizeof(dp));

        temp1 = ABS(start[1][0],start[1][1])+2;
        temp2 = ABS(start[1][0],start[1][1])+2;
        for(int i=2;i<n;i++){
            
        }
        cout << solve(0,1) << "\n";
    }
    return 0;
}