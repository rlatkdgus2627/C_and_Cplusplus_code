#include <iostream>

using namespace std;

class Example{
private:
    int num1;
    int num2;
public:
    Example(int n1,int n2): num1(n1),num2(n2){}

    Example(const Example& copy):num1(copy.num1),num2(copy.num2){}

    void ShowExample(){
        cout << num1 << " " << num2 << endl;
    }
};

int main(){
    Example ex1(15,30);
    Example ex2 = ex1;
    ex2.ShowExample();
    return 0;
}