#include <bits/stdc++.h>

using namespace std;

int n;
int dp[5001][2];
char number[5001];

int solve(int i, int c){
    if(i == n) return 1;
    if(number[i] == '0')    return 0;
    
    int& ret = dp[i][c];
    if(ret != 0)    return ret;

    ret += solve(i+1,0)%1000000;

    if(i+1<n){
        if(number[i] == '1'){
            ret += solve(i+2,1)%1000000;
        }
        else if(number[i] == '2' && number[i+1] <= '6'){
            ret += solve(i+2,1)%1000000;
        }   
    }

    ret %= 1000000;
    return ret;
}

int main(){
    cin >> number;
    n = strlen(number);
    cout << solve(0,0);
    return 0;
}