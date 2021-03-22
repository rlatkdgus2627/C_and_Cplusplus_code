#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> p;

int t;
int n, top;
long long num[300001];
long long ans;
pair<long long, long long> S[300001];

void solve(){
    long long segMin, segMax;
    bool check = true;
    int curMin, indexOfMin, x;
    vector<p>v;
    scanf("%d",&x);
    segMin = segMax = x;
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        if(x < segMax){
            v.push_back(make_pair(segMin,segMax));
            segMin = segMax = x;
        }
        else{
            segMax = x;
        }
    }
    v.push_back(make_pair(segMin,segMax));
    top = -1;

    curMin = v[0].first; indexOfMin = 0;
    for(int i=0;i<v.size();i++){
        if(curMin > v[i].first){
            curMin = v[i].first;
            S[++top] = v[i];
            indexOfMin = top;
            continue;
        }
        for(int j = indexOfMin; j <= top ; j++){
            if(S[j].first <= v[i].first && S[j].second <= v[i].second){
                v[i].first = S[j].first;
                top = j - 1;
                break;
            }
        }
        S[++top] = v[i];
        if(S[top].first <= curMin){
            curMin = S[top].first;
            indexOfMin = top;
        }
    }
    ans = top+1;
}

int main(){
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d",&n);
        solve();
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}