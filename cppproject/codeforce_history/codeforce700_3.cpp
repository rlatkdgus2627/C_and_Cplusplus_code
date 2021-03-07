#include <bits/stdc++.h>
#define INF 0x7fffffff

using namespace std;

int n,ans,num[100002],guess,ret,temp;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    
    cin >> n;
    num[0] = INF;
    num[n+1] = INF;
    guess = 1;

    set<int>s;

    for(int i=1;i<=n;i++){
        s.insert(i);
    }

    while(){
        cout << "? " << guess << "\n";
        cin << ret;

        num[guess] = ret;
        temp = s.lower_bound(ret) - s.begin();
        
        s.remove(guess);
        
    }
    
    cout << "! " << guess << endl;
    cout.flush();
    return 0;
}