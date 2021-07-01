#include <bits/stdc++.h>

using namespace std;

int n, m;
string dp[101][101];

string operator+(const string& lhs, const string& rhs){
    string temp = lhs;
    string temp2 = rhs;
    string ret = "";
    int sum = 0;
    while(!temp.empty() || !temp2.empty() || sum){
        if(!temp.empty()){
            sum += temp.back() - '0';
            temp.pop_back();
        }
        if(!temp2.empty()){
            sum += temp2.back() - '0';
            temp2.pop_back();
        }
        ret.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0 || j == 0)    dp[i][j] = "1";
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout << dp[n][m];
}