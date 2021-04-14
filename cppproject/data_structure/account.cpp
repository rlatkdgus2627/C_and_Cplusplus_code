//이 프로그램은 계좌를 생성하고, 입출금을 처리하고, 등록한 계좌 정보를 출력할 수 있는 프로그램입니다.
//2020112036 김상현
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class bank{
    char name[20];
    int acno;
    char actype[5]; //null문자 때문에 size 1을 더 추가하였습니다.
    float balance;

public:
    void init();
    void deposit();
    void withdraw();
    void disp_det();
};
//member functions of bank class
void bank::init(){
    cout << "\nNew Account" << endl;
    cout << "Enter the Name of the depositor : ";
    cin >> name;
    cout << "Enter the Account Number : ";
    cin >> acno;
    cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
    cin >> actype;
    cout << "Enter the Amount to Deposit : ";
    cin >> balance;
}
void bank::deposit(){
    float add;
    cout << "\nDepositing" << endl;
    cout << "Enter the amount to deposit : ";
    cin >> add;
    balance += add;
}
void bank::withdraw(){
    float sub;
    cout << "Withdrwal" << endl;
    cout << "Enter the amount to withdraw : ";
    cin >> sub;
    if(sub > balance)   cout << "You don't have enough money!" << endl; //예외 처리 (-잔액은 불가능)
    else balance -= sub;
}
void bank::disp_det(){   
    cout << "\nAccount Details" << endl;
    cout << "Name of the depositor : " << name << endl;
    cout << "Account Number : " << acno << endl;
    cout << "Account Type : " << actype << endl;
    cout << "Balance : " << "$" << balance << endl;
}
// main function , exectution starts here
int main(void){
    // clrscr();
    bank obj;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3. Withdraw\n4. See A / c Status\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            obj.disp_det();
            cout << "EXITING PROGRAM.";
            break;
        case 1:
            obj.init();
            break;
        case 2:
            obj.deposit();
            break;
        case 3:
            obj.withdraw();
            break;
        case 4:
            obj.disp_det();
            break;
        default:
            cout << "Illegal Option" << endl;
        }
    }
    _getch();
    return 0;
}