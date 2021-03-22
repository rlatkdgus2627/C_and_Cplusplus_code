#include <bits/stdc++.h>

using namespace std;

int t, n, k, ans, mex, Max;
int num[100001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        mex = Max = 0;
        set<int>S;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        sort(num,num+n);
        for(int i=0;i<n;i++){
            if(num[i] == mex)   mex++;
            else if(num[i] > Max)   Max = num[i];
            S.insert(num[i]);
        }
        if(k == 0){
            cout << n << "\n";
            continue;
        }
        if(mex < Max){
            S.insert((mex+Max+1)/2);
            cout << S.size() << "\n";
        }
        else{
            cout << mex+k << "\n";
        }
    }
}