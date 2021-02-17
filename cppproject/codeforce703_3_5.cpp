#include <bits/stdc++.h>

using namespace std;

int t, n, num[200000], most, sec, cur, temp;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n;
        most = sec = temp = 0;
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        sort(num,num+n);
        cur = num[0];
        temp = 1;
        for(int i=0;i<n;i++){
            if(cur != num[i]){
                temp = 1;
                cur = num[i];
            }
            else{
                temp++;
                cout << "temp:" << temp << "\n";
                if(temp > most){
                    sec = most;
                    most = temp;
                }
                else if(temp > sec && temp <= most){
                    sec = temp;
                }
            }
        }
        cout << most << " " << sec << "\n";
        cout << min(most - sec + n - (most + sec), n - most) << "\n";
    }
    return 0;
}