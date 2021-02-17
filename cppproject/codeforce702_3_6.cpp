#include <bits/stdc++.h>

using namespace std;

pair<int,int> player[200001];

vector<int> ans;

int t, n;

long long sum;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> t; 
    int x;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            player[i].first = x;
            player[i].second = i+1;
        }
        sort(player, player+n,[](pair<int,int> a,pair<int,int> b){
            return a.first > b.first;
        });

        sum = player[0].first;
        ans.push_back(player[0].second);
        for(int i=1;i<n;i++){
            if(sum < player[i].first){
                ans.clear();
                ans.push_back(player[i].second);
            }
            else{
                ans.push_back(player[i].second);
            }

            sum += player[i].first;
        }
        sort(ans.begin(),ans.end());
        cout << ans.size() << "\n";
        for(int x:ans){
            cout << x << " ";
        }
        cout << "\n";

    }
    return 0;
}