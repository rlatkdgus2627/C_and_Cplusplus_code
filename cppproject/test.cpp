#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int a = 10;
    
    //int to string
    string str = to_string(a);

    str = "000"+str;
    //string to int
    int b = stoi(str);

    cout << str << endl;
    cout << b << endl;
    cout << a+b << endl;
}