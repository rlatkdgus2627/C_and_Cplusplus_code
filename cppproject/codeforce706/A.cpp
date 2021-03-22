#include <bits/stdc++.h>

using namespace std;

int t,n,k;
char input[101];
int cnt;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> k;
        cin >> input;
        for(int i=0;i<n/2;i++){
            if(input[i] == input[n-1-i]){
                cnt++;
            }
            else break;
        }
        if((n%2 == 1 && cnt >= k) || (n%2 == 0 && cnt > k) || k == 0)    cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}