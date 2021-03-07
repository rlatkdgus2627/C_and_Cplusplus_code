#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll matrix[2][2]={{1,1},{1,0}}, ans[2][2]={{1,0},{0,1}},temp[2][2];

int main(){
    cin >> n;
    if(n==1){
        cout << matrix[0][1] << endl;
    }
    else{
        while(n){
            if(n%2==1){
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        temp[i][j] = ans[i][j];
                        ans[i][j] = 0;
                    }
                }
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        for(int k=0;k<2;k++){
                            ans[i][j] += (temp[i][k]*matrix[k][j])%(ll)(1e9+7);
                        }
                        ans[i][j] %= (ll)(1e9+7);
                    }
                }
            }

            for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        temp[i][j] = matrix[i][j];
                        matrix[i][j] = 0;
                    }
                }
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        matrix[i][j] += (temp[i][k]*temp[k][j])%(ll)(1e9+7);
                    }
                    matrix[i][j] %= (ll)(1e9+7);
                }
            }  
            n/=2LL;
        }
        cout << ans[0][1] << endl;
    }
    return 0;
}