#include <bits/stdc++.h>

using namespace std;

int n,k;

struct node{
    map<string, node> next;
};

void insert(node& cur, vector<string>input, int i){
    if(i == k)   return;
    if(cur.next.find(input[i]) == cur.next.end())   cur.next[input[i]] = node();
    insert(cur.next[input[i]], input, i+1);
}

void dfs(node& cur, int depth){
    for(auto i = cur.next.begin(); i != cur.next.end(); i++){
        for(int j=0;j<depth;j++){
            cout << "--";
        }
        cout << i->first << "\n";
        dfs(i->second, depth+1);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    node root = node();
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        vector<string>input;
        for(int j=0;j<k;j++){
            cin >> str;
            input.push_back(str);
        }
        insert(root,input,0);
    }
    dfs(root,0);
    return 0;
}