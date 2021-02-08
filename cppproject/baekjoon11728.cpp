//FAST IO로 뚤리는지 테스트
#include <bits/stdc++.h>

using namespace std;

int num[2000000];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int i=0,n,m;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    for(i=n;i<n+m;i++){
        cin >> num[i];
    }
    sort(num,num+n+m);
    for(int i=0;i<n+m;i++){
        cout << num[i] << " ";
    }
    return 0;
}