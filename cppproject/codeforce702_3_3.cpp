#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll>v;

int t;
ll x;
bool check;

int binarySearch(int left,int right,ll find){
    int mid;
    if(left>right)  return 0;
    mid=(left+right)/2;
    if(find==v[mid])    return 1;
    else if(find<v[mid]){
        binarySearch(left,mid-1,find);
    }
    else if(find>v[mid]){
        binarySearch(mid+1,right,find);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> x;
        check = false;
        v.clear();
        int temp = cbrt(x);
        for(int i=1;i<=temp;i++){
            v.push_back((ll)i*(ll)i*(ll)i);
        }
        for(int i=0;i<temp;i++){
            if(binarySearch(0,temp,x-v[i])) check = true;
        }
        if(check)   cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}