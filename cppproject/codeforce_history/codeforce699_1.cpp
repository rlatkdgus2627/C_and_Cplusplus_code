#include <bits/stdc++.h>

using namespace std;

int t;
char str[100001];

int main(){
    int x,y;
    int u,d,l,r;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        u=d=l=r=0;
        cin >> x >> y;
        cin >> str;
        for(int i=0;str[i]!='\0';i++){
            if(str[i] == 'U'){
                u++;
            }
            if(str[i] == 'D'){
                d++;
            }
            if(str[i] == 'L'){
                l++;
            }
            if(str[i] == 'R'){
                r++;
            }
        }
        if(x>0 && y>0){
            if(r>=x && u>=y){
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
        if(x<=0 && y>0){
            if(l>=labs(x) && u>=y){
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
        if(x>0 && y<=0){
            if(r>=x && d>=labs(y)){
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
        if(x<=0 && y<=0){
            if(l>=labs(x) && d>=labs(y)){
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
    }
    return 0;
}