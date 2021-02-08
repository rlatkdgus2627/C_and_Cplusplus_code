#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll num[1001];

bool cmp(ll a, ll b){
    
    string temp1 = to_string(a);
    string temp2 = to_string(b);

    return (temp1+temp2).compare(temp2+temp1)>0;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    
    sort(num,num+n,cmp);

    if(n == 1){
        cout << num[0];
        return 0;
    }
    else if(num[0] == 0){
        cout << "0";
        return 0;
    }

    for(int i=0;i<n;i++){
        cout << num[i];
    }
    return 0;
}