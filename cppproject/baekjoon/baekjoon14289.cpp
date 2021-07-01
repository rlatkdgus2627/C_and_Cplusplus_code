#include <bits/stdc++.h>

using namespace std;

long long D;

const long long MOD = 1e9+7;

long long matrix[51][51];
long long temp[51][51], ans[51][51];

int n, m;

void multiple1() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = ans[i][j];
			ans[i][j] = 0LL;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans[i][j] += (temp[i][k] * matrix[k][j]) % MOD;
			}
			ans[i][j] %= MOD;
		}
	}

}

void multiple2(){
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = matrix[i][j];
			matrix[i][j] = 0LL;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				matrix[i][j] += (temp[i][k]  * temp[k][j]) % MOD;
			}
			matrix[i][j] %= MOD;
		}
	}
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
		cin >> x >> y;
        matrix[x-1][y-1] = matrix[y-1][x-1] = 1;
	}
   
    for (int i = 0; i < n; i++) {
		ans[i][i] = 1LL;
	}
    cin >> D;

	while(D){
		if(D&1)	multiple1();
		D/=2;
		multiple2();
	}

    cout << ans[0][0];
    return 0;
}