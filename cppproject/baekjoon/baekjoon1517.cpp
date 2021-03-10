#include <bits/stdc++.h>

using namespace std;

int n, num[500001], temp[500001];
long long ans;

void merge(int s, int mid, int e){
    int t = 0, l = s, r = mid+1;
    while(l <= mid || r <= e){
        if(l<=mid&&(r>e||num[l]<=num[r])){
            temp[t++] = num[l++];
        }
        else{
            ans += (long long)mid - l + 1;
            temp[t++] = num[r++];
        }
    }
    for(int i=0;i<t;i++){
        num[s+i] = temp[i];
    }
}

void mergeSort(int s, int e){
    int mid = (s+e)/2;
    if(s<e){
        mergeSort(s,mid);
        mergeSort(mid+1,e);
        merge(s,mid,e);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    mergeSort(1,n);
    cout << ans;
    return 0;
}