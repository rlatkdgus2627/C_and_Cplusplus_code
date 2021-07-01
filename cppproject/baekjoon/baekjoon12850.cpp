#include <bits/stdc++.h>

using namespace std;

long long D;

const long long MOD = 1e9+7;

long long matrix[8][8] = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,0,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,0,1,0,1,1,0},
    {0,0,1,1,1,0,0,1},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,1,1,0},
};


long long temp[8][8], ans[8][8];

void multiple1() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			temp[i][j] = ans[i][j];
			ans[i][j] = 0LL;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				ans[i][j] += (temp[i][k] * matrix[k][j]) % MOD;
			}
			ans[i][j] %= MOD;
		}
	}

}

void multiple2(){
    for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			temp[i][j] = matrix[i][j];
			matrix[i][j] = 0LL;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				matrix[i][j] += (temp[i][k]  * temp[k][j]) % MOD;
			}
			matrix[i][j] %= MOD;
		}
	}
}

int main(){
    cin >> D;
   
    for (int i = 0; i < 8; i++) {
		ans[i][i] = 1LL;
	}

	while(D){
		if(D&1)	multiple1();
		D/=2;
		multiple2();
	}

    cout << ans[0][0];
    return 0;
}