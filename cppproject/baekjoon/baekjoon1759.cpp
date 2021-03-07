#include <bits/stdc++.h>

using namespace std;

int l,c;
char ch[16];
char st[16];

void solve(int n,int p,bool complete1,int complete2){
    if(n == l && complete1 && complete2 >= 2){
        st[n] = '\0';
        cout << st << "\n";
    }
    for(int i=p;i<c;i++){
        st[n] = ch[i];
        if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')    solve(n+1,i+1,true,complete2);
        else solve(n+1,i+1,complete1,complete2+1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> l >> c;
    for(int i=0;i<c;i++){
        cin >> ch[i];
        cin.clear();
    }
    sort(ch,ch+c);
    solve(0,0,false,0);
    return 0;
}