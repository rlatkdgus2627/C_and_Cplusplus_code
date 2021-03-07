#include <iostream>

using namespace std;

unsigned int input, output;

int main(){
    cin >> input;

   unsigned int temp; 

    for(int i=0;i<4;i++){
        temp = input % 0x100;
        input = input >> 8;
        output = (output << 8) + temp;
    }

    cout << output;

    return 0;
}