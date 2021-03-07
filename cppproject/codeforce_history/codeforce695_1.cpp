#include <bits/stdc++.h>

using namespace std;

int number[10], n, T;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> T;
    for(int i=0;i<10;i++)    number[i]=i;

    while(T--){
       cin >> n;
       if(n==1) cout<< "9" << "\n";
       else if(n==2) cout<< "98" << "\n"; 
       else if(n==3) cout<< "989" << "\n";
       else{
           cout << "989";
           for(int i=0;i<n-3;i++){
               cout << number[i%10];
           }
           cout << "\n";
       }
    }
    return 0;
}