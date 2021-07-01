#include <bits/stdc++.h>

using namespace std;

int n;
int num1[1000001], num2[1000001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> v;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> num1[i];
        num2[i] = num1[i];
    }
    sort(num2,num2+n);
    for(int i = 0 ; i < n; i++){
        if(v.empty() || v.back() != num2[i]){
            v.push_back(num2[i]);
        }
    }
    for(int i = 0 ; i < n; i++){
        cout << lower_bound(v.begin(),v.end(),num1[i]) - v.begin() << " ";
    }
    return 0;
}