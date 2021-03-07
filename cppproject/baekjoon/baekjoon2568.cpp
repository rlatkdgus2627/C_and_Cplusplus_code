#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int> > num;
vector<int>v;
pair<int,int> ans[100001];

bool check[500001];

int main(){
    int s,e;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++){
        cin >> s >> e;
        num.push_back(make_pair(s,e));
    }

    sort(num.begin(),num.end(),[](pair<int,int> a, pair<int, int> b){
        return a.first < b.first;
    });

	v.push_back(0);

	for (int i = 0; i < num.size(); i++) {
		if (num[i].second > v.back()) {
			v.push_back(num[i].second);
			ans[i] = make_pair(v.size()-1,num[i].second);
		}
		else {
			auto t = lower_bound(v.begin(), v.end(), num[i].second);
			*t = num[i].second;
            ans[i] = make_pair(t - v.begin(),num[i].second);
		}
	}

	int temp = v.size()-1;

    cout << num.size() - temp << "\n";

	for (int i = n-1; i >= 0 ; i--) {
		if (ans[i].first == temp)
		{
			check[ans[i].second] = true;
			temp--;
		}
	}

    for (int i = 0; i < num.size(); i++) {
        if(check[num[i].second])    continue;
        cout << num[i].first << "\n";
    }
	
	return 0;
}