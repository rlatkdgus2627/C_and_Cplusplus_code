//김상현
//2021-03-28
//palindrome.cpp
//스택을 이용해서 펠린드롬 판별.
#include "stackarr.cpp"
#include <cstring>

int main() {
	char inputString[101];
	int len;
	bool check;
	cout << "Enter strings(Program will be terminated, if cin receive EOF(input Ctrl+z if you use console(terminal)))" << endl;
	while (true) {
		check = true;
		cin >> inputString;
		if (cin.eof()) {
			break;
		}
		Stack<char> S(len = strlen(inputString));
		for (int i = 0; i < len; i++) {
			S.push(inputString[i]);
		}
		for (int i = 0; i < len; i++) {
			if (S.pop() != inputString[i]) {
				check = false;
				break;
			}
		}
		cout << (check ? "Yes" : "No") << endl;
	}
	return 0;
}