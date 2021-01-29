#include <bits/stdc++.h>

using namespace std;

int t,q,d;

int numset_3[3] = {3,13,23};
int numset_4[4] = {4,14,24,34};
int numset_6[6] = {6,16,26,36,46,56};
int numset_7[7] = {7,17,27,37,47,57,67};
int numset_8[8] = {8,18,28,38,48,58,68,78};
int numset_9[9] = {9,19,29,39,49,59,69,79,89};

bool getcase[6][101];

void solve4(int x){
    if(x >= 40) return;
    
    getcase[0][x] = true;
    for(int i=0;i<4;i++){
        solve4(x+numset_4[i]);
    }
}

void solve6(int x){
    if(x >= 60) return;
    
    getcase[1][x] = true;
    for(int i=0;i<6;i++){
        solve6(x+numset_6[i]);
    }
}

void solve7(int x){
    if(x >= 70) return;
    
    getcase[2][x] = true;
    for(int i=0;i<7;i++){
        solve7(x+numset_7[i]);
    }
}

void solve8(int x){
    if(x >= 80) return;
    
    getcase[3][x] = true;
    for(int i=0;i<7;i++){
        solve8(x+numset_8[i]);
    }
}

void solve9(int x){
    if(x >= 90) return;
    
    getcase[4][x] = true;
    for(int i=0;i<9;i++){
        solve9(x+numset_9[i]);
    }
}

void solve3(int x){
    if(x >= 30) return;
    getcase[5][x] = true;
    for(int i=0;i<3;i++){
        solve3(x+numset_3[i]);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve3(0);
    solve4(0);
    solve6(0);
    solve7(0);
    solve8(0);
    solve9(0);

    cin >> t;
    while(t--){
        cin >> q >> d;
        for(int i=0;i<q;i++){
            int num;
            cin >> num;
            if(num >= 10*d || d == 1 || (d == 2 && num%2 == 0) || (d == 5 && num%5 == 0)){
                cout << "YES" << "\n";
            }
            else{
                if(d == 3){
                    if(getcase[5][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }
                if(d == 4){
                    if(getcase[0][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }
                if(d == 6){
                    if(getcase[1][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }
                if(d == 7){
                    if(getcase[2][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }
                if(d == 8){
                    if(getcase[3][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }
                if(d == 8){
                    if(getcase[4][num] == true){
                        cout << "YES" << "\n";
                    }
                    else{
                        cout << "NO" << "\n";
                    }
                }

            }
        }
    }
    return 0;
}