#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,ans;
ll num[2001];

int main(){
    
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    sort(num,num+n);

    int s,e;
    for(int i=0;i<n;i++){
        s = 0;  e = n-1;
        while(s<e){
            if(num[s] + num[e] == num[i]){
                if(s!=i&&e!=i){
                    ans++;
                    break;
                }
                if(s == i)  s++;
                if(e == i) e--;
            }
            else if(num[s] + num[e] < num[i]){
                s++;
            }
            else{
                e--;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}