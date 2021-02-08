#include <bits/stdc++.h>

using namespace std;

int t,cur[100001],ans[100001],n,m;
int exist[100001];
int trash[100001];

vector<int>want[100001];
vector<pair<int,int> >bin;


int main(){
    bool check;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        check = true;
        int c,p;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> cur[i];
            want[i].clear();
            exist[i] = -1;
            trash[i] = -1;
        }
        want[n].clear();
        exist[n] = -1;
        trash[n] = -1;
        bin.clear();
        for(int i=0;i<n;i++){
            cin >> c; 
            if(c != cur[i]) want[c].push_back(i);
            else{
                exist[c] = i;
            }
        }
        for(int i=0;i<m;i++){
            cin >> p;
            if(want[p].size() > 0){
                if(bin.size() > 0){
                    ans[bin.back().first] = want[p].back();
                    trash[bin.back().second] = -1;
                    bin.pop_back();
                }
                if(want[p].size() - 1 == 0){
                    exist[p] = want[p].back();
                }
                ans[i] = want[p].back();
                want[p].pop_back();
                
            }
            else{
                if(exist[p] == - 1){
                    if(trash[p] == -1){
                        trash[p] = i;
                        bin.push_back(make_pair(i,p));
                    }
                    else ans[i] = ans[]; 
                }
                else{
                    ans[i] = exist[p];
                    if(bin.size() > 0){
                        ans[bin.back().first] = exist[p];
                        trash[bin.back().second] = -1;
                        bin.pop_back();
                    }
                }
            }
        }

        if(bin.size() > 0) check = false;
        else{
            for(int i=1;i<=n;i++){
                if(want[i].size() > 0){
                    check = false;
                    break;
                }
            }
        }
        if(check == true){
            cout << "YES" << "\n";
            for(int i=0;i<m;i++){
                cout << ans[i]+1 << " ";
            }
            cout<< "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}