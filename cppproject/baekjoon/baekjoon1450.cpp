#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> sumset1, sumset2, case1, case2;

int n;

ll c;
ll ans;

void getSum1(int i, ll s){
    if(i == case1.size()){
        sumset1.push_back(s);
        return;
    }
    getSum1(i+1,s+case1[i]);
    getSum1(i+1,s);
}
void getSum2(int i, ll s){
    if(i == case2.size()){
        sumset2.push_back(s);
        return;
    }
    getSum2(i+1,s+case2[i]);
    getSum2(i+1,s);
}

int main(){

    ll x;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> x;
        case1.push_back(x);
    }

    for(int i=0;i<n/2;i++){
        x = case1.back();
        case2.push_back(x);
        case1.pop_back();
    }

    getSum1(0,0);
    getSum2(0,0);

    sort(sumset2.begin(),sumset2.end());

    for(auto p : sumset1){
        ans += upper_bound(sumset2.begin(),sumset2.end(),c-p)-sumset2.begin();
    }

    cout << ans << endl;
    return 0;
}