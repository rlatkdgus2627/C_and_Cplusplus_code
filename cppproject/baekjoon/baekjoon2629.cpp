#include <bits/stdc++.h>

using namespace std;

bool possible[31][30002];

int n,q,sum;
int weight[30];

void solve(int i, int w){

    if(possible[i][w]) return;
    possible[i][w] = true;

    if(i+1 <= n){
        solve(i+1,w+weight[i]);
        solve(i+1,w-weight[i]);
        solve(i+1,w);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int input;
    bool check;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }
    solve(0,15001);

    cin >> q;
    for(int i=0;i<q;i++){
        cin >> input;

        if(input > 15000){
            cout << "N" << " ";
            continue;
        }

        check = false;
        for(int i=0;i<=n;i++){
            if(possible[i][input+15001]){
                cout << "Y" << " ";
                check = true;
                break;
            }
        }
        if(!check){
            cout << "N" << " ";
        }
    }
    return 0;
}