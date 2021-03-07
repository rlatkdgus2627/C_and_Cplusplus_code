#include <bits/stdc++.h>

using namespace std;

int nameLen[23];
long long ans;
int n,k,p;

queue<unsigned long>Q;
string name;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<min(k+1,n);i++){
        cin >> name;
        p = name.length();
        Q.push(p);
        ans += nameLen[p];
        nameLen[p]++;
    }
    for(int i=k+1;i<n;i++){
        p = Q.front();
        nameLen[p]--;
        Q.pop();
        cin >> name;
        p = name.length();
        Q.push(p);
        ans += nameLen[p];
        nameLen[p]++;
    }
    cout << ans << "\n";
    return 0;
}