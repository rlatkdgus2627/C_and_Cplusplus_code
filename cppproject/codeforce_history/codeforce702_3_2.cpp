#include <bits/stdc++.h>

using namespace std;

int t,n,c0,c1,c2,ans;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;

    int x;
    while(t--){
        cin >> n;
        c0 = c1 = c2 = 0;
        for(int i=0;i<n;i++){
            cin >> x;
            if(x%3 == 0){
                c0++;
            }
            else if(x%3 == 1){
                c1++;
            }
            else{
                c2++;
            }

        }

        if(c0 >= n/3 && c1 >= n/3){
            cout << (c0-(n/3))*2 + c1-(n/3) << "\n";
        }
        else if(c1 >= n/3 && c2 >= n/3){
            cout << (c1-(n/3))*2 + c2-(n/3) << "\n";
        }
        else if(c2 >= n/3 && c0 >= n/3){
            cout << (c2-(n/3))*2 + c0-(n/3) << "\n";
        }
        else if(c0 > n/3){
            cout << (n/3)-c1 + ((n/3)-c2)*2 << "\n";
        }
        else if(c1 > n/3){
            cout << (n/3)-c2 + ((n/3)-c0)*2 << "\n";
        }
        else if(c2 > n/3){
            cout << (n/3)-c0 + ((n/3)-c1)*2 << "\n";
        }
    }

    return 0;
}