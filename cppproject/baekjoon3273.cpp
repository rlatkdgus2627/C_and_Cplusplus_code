#include <bits/stdc++.h>

using namespace std;

int n, x, ans;
int number[100001];


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> number[i];
    }
    cin >> x;
    sort(number,number+n);
    
    int a = 0, b = n-1;

    while(a < b){
        if(number[a]+number[b]>x){
            b--;
        }
        else if(number[a]+number[b]<x){
            a++;
        }
        else{
            ans++;
            a++;
            b--;
        }
    }

    cout << ans;
    return 0;
}