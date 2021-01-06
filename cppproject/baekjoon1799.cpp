#include <cstdio>
#include <vector>
#include <utility>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int n, ans;

vector<pair<int,int> >vcWhite;
vector<pair<int,int> >vcBlack;

bool check1[21], check2[21];

int solve1(int x){
    if(x==vcWhite.size()){
        return 0;
    }
    int ret = 0;

    bool& checking1 = check1[vcWhite[x].first+vcWhite[x].second];
    bool& checking2 = check2[vcWhite[x].first-vcWhite[x].second+10];

    if(!checking1&&!checking2){
        checking1 = checking2 = true;
        ret = solve1(x+1) + 1;
        checking1 = checking2 = false;
    }
    
    ret = max(ret,solve1(x+1));

    return ret;
}

int solve2(int x){
    if(x==vcBlack.size()){
        return 0;
    }
    int ret = 0;

    bool& checking1 = check1[vcBlack[x].first+vcBlack[x].second];
    bool& checking2 = check2[vcBlack[x].first-vcBlack[x].second+10];

    if(!checking1&&!checking2){
        checking1 = checking2 = true;
        ret = solve2(x+1) + 1;
        checking1 = checking2 = false;
    }
    
    ret = max(ret,solve2(x+1));

    return ret;
}

int main(){
    scanf("%d",&n);
    FOR(i,n){
        FOR(j,n){
            int x;
            scanf("%d",&x);
            if(x == 1){
                if((i%2==0&&j%2==0)||(i%2==1&&j%2==1))  vcWhite.push_back(make_pair(i,j));
                else vcBlack.push_back(make_pair(i,j));
            }
        }
    }
    printf("%d",solve1(0)+solve2(0));
    return 0;
}