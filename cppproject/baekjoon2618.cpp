#include <bits/stdc++.h>

using namespace std;

int trace[1001][1001],n,w;

int dp[1001][1001],ans;

pair<int,int> locate[1001];

int ABS(int a){
    return a>0 ? a : (-1*a);
}

int solve(int c1,int c2){
    if(c1 == w || c2 == w){
        return 0;
    }
    int& ret = dp[c1][c2];
    int temp;
    if(ret != 0) return ret;

    if(c1 == 0){
        ret = ABS(locate[c2+1].first - 1) + ABS(locate[c2+1].second - 1) + solve(c2+1,c2);
        temp = ABS(locate[c2+1].first - locate[c2].first) + ABS(locate[c2+1].second - locate[c2].second) + solve(c1,c2+1);
        if(ret > temp){
            ret = temp;
            trace[c1][c2] = 2;
        }
        else{
            trace[c1][c2] = 1;
        }
    }
    else if(c2 == 0){
        ret = ABS(locate[c1+1].first - locate[c1].first) + ABS(locate[c1+1].second - locate[c1].second) + solve(c1+1,c2);
        temp = ABS(locate[c1+1].first - n) + ABS(locate[c1+1].second - n) + solve(c1,c1+1);
        if(ret > temp){
            ret = temp;
            trace[c1][c2] = 2;
        }
        else{
            trace[c1][c2] = 1;
        }
    }
    else if(c1 < c2){
        ret = ABS(locate[c2+1].first - locate[c1].first) + ABS(locate[c2+1].second - locate[c1].second) + solve(c2+1,c2);
        temp = ABS(locate[c2+1].first - locate[c2].first) + ABS(locate[c2+1].second - locate[c2].second) + solve(c1,c2+1);
        if(ret > temp){
            ret = temp;
            trace[c1][c2] = 2;
        }
        else{
            trace[c1][c2] = 1;
        }
    }
    else if(c1 > c2){
        ret = ABS(locate[c1+1].first - locate[c1].first) + ABS(locate[c1+1].second - locate[c1].second) + solve(c1+1,c2);
        temp = ABS(locate[c1+1].first - locate[c2].first) + ABS(locate[c1+1].second - locate[c2].second) + solve(c1,c1+1);
        if(ret > temp){
            ret = temp;
            trace[c1][c2] = 2;
        }
        else{
            trace[c1][c2] = 1;
        }
    }
    return ret;
}

void printTrace(int c1,int c2){
    if(c1 == w || c2 == w) return;
    cout << trace[c1][c2] << "\n";
    int temp = max(c1,c2);
    if(trace[c1][c2]==1){
        printTrace(temp+1,c2);
    }
    if(trace[c1][c2]==2){
        printTrace(c1,temp+1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> w;
    for(int i=1;i<=w;i++){
        cin >> locate[i].first >> locate[i].second;
    }
    int ret1 = solve(1,0)+ABS(locate[1].first - 1)+ABS(locate[1].second - 1);
    int ret2 = solve(0,1)+ABS(locate[1].first - n)+ABS(locate[1].second - n);

    if(ret1 < ret2){
        trace[0][0] = 1;
        ans = ret1;
    }
    else{
        trace[0][0] = 2;
        ans = ret2;
    }
    cout << ans << "\n";
    printTrace(0,0);
    return 0;
}