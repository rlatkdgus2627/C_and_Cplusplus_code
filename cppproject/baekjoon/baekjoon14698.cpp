#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,n;

ll temp;

int main(){

    ll x,y;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while(t--){
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        temp = 1LL;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            pq.push(x);
        }
        
        while(pq.size() != 1){
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            pq.push(x*y);
            temp = ((temp%1000000007)*((x*y)%1000000007))%1000000007;
        }

        cout << temp << "\n";
        
    }
    return 0;
}