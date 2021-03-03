#include <bits/stdc++.h>

using namespace std;

int n;

long long ans;

int main(){

    long long x,a,b;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    for(int i=0;i<n;i++){
        cin >> x;
        pq.push(x);
    }

    while(pq.size()!=1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans += a+b;
    }

    cout << ans << "\n";

    return 0;
}