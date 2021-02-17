#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int a;
    cin >> a;
    cin.ignore();
    while(a--){
        string b;
        getline(cin,b);
        int c=count(b.begin(),b.end(),'g');
        c+=count(b.begin(),b.end(),'G');
        int d=count(b.begin(),b.end(),'b');
        d+=count(b.begin(),b.end(),'B');
        if(c>d){
            cout<<b<<" is GOOD\n";
        }
        else if(c==d){
            cout<<b<<" is NEUTRAL\n";
        }
        else if(c<d){
            cout<<b<<" is A BADDY\n";
        }
    }
}