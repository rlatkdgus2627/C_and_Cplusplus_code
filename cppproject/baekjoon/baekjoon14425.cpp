#include <bits/stdc++.h>

using namespace std;

int n, m, ans;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string input;
    set<string>S;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> input;
        S.insert(input);
    }
    for(int i=0;i<m;i++){
        cin >> input;
        if(S.find(input) != S.end())    ans++;
    }
    cout << ans;
    return 0;
}