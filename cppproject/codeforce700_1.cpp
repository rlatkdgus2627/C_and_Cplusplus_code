#include <bits/stdc++.h>

using namespace std;

int t;
char str[51], ans[51];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> str;
        int n = strlen(str);
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                if(str[i] == 'a')   ans[i] = 'b';
                else ans[i] = 'a';
            }
            else{
                if(str[i] == 'z')   ans[i] = 'y';
                else ans[i] = 'z';
            }
        }
        ans[n]='\0';
        cout << ans << "\n";
    }
    return 0;
}