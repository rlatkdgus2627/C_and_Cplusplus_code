#include <iostream>

using namespace std;

typedef long long ll;

int road[100001];
int cost[100001];

int n;

ll solve(){
    ll ans=0,dist;
    int i=0,j;
    while(i<n-1){
        dist = road[i];
        for(j=i+1;j<n-1;j++){
            if(cost[i]>cost[j]) break;

            dist += road[j];
        }
        ans += cost[i]*dist;
        i = j;
    }

    return ans;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n-1;i++){
        cin >> road[i];
    }
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    cout << solve() << endl;
}