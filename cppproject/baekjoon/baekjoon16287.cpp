#include <bits/stdc++.h>

using namespace std;

int w, n;
int parcel[5001];
bool weight[800001];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> parcel[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(w-(parcel[i]+parcel[j]) >= 0 && weight[w-(parcel[i]+parcel[j])]){
                cout << "YES";
                return 0;
            }
        }
        for(int j = 0; j < i; j++){
            weight[parcel[i]+parcel[j]] = true;
        }
    }
    cout << "NO";
    return 0;
}