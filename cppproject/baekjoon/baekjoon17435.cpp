#include <bits/stdc++.h>

using namespace std;

int m;
int num[200001];
int q;
int table[200001][19];

void calculate(){
    for(int i=1;i<=m;i++){
        table[i][0] = num[i]; 
    }
    for(int i=1;i<19;i++){
        for(int j=1;j<=m;j++){
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
}

int main(){
    int n,x;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> num[i];
    }
    calculate();
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> n >> x;
        for(int j=18;j>=0;j--){
            if(n&(1<<j))    x = table[x][j];
        }
        cout << x << "\n";
    }
    return 0;
}