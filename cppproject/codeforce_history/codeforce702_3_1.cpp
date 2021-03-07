#include <bits/stdc++.h>

using namespace std;

int t,n,num[50],ans,k;

int main(){

    int temp;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        ans = 0;
        temp = num[0];
        k=1;
        while(k<n){
            if(max(temp,num[k]) <= 2*min(temp,num[k])){
                temp = num[k];
                k++;
            }
            else{
                ans++;
                if(temp < num[k]){
                    temp = temp*2;
                }
                else{
                    temp = (temp+1)/2;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}