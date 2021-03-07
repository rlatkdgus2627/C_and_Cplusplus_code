#include <bits/stdc++.h>

using namespace std;

int n,ans;

int main(){
    int temp,x;
    int check;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    cin >> x;
    check = 1;
    ans = n;
    temp = x;
    for(int i=1;i<n;i++){
        cin >> x;
        if(temp == x){
            check++;
            if(check >= 3){
                ans--;
            }
        }
        if(temp != x){
            check = 1;
            temp = x;
        }
    }
    cout << ans;
}