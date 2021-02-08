#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int t,n;

ll a,b;

pair<ll, ll> monster[100001];
int main(){
    ll temp;
    bool check;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        check = true;
        cin >> a >> b >> n;

        for(int i=0;i<n;i++){
            cin >> monster[i].first; //attack
        }
        for(int i=0;i<n;i++){
            cin >> monster[i].second; //health
        }

        sort(monster,monster+n);

        for(int i=0;i<n-1;i++){
            temp = (ll)ceil((double)monster[i].second / a);
            if(b - temp * monster[i].first < 0){
                check = false;
                break;
            }
            b -= temp * monster[i].first;
        }

        temp = (ll)ceil((double)monster[n-1].second / a);
        if(b - (temp-1) * monster[n-1].first < 0){
            check = false;
        }

        if(check)    cout << "YES" << "\n";
        else    cout << "NO" << "\n";

    }
    return 0;
}