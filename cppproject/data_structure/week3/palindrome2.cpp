//김상현
//2021-03-28
//palindrome2.cpp
//펠린드롬을 만족하기 위해서 제거해야 하는 문자의 인덱스 출력(지워야 하는 문자는 단 1개라고 가정)

#include "stackarr.cpp"
#include <cstring>
#include <utility>

bool checkPalindrome(const char* str, const int exclude) {
	bool ret = true;
	int len;
	Stack<char> S((len = strlen(str))-1);
	for (int i = 0; i < len; i++) {
		if(i != exclude)	S.push(str[i]);
	}
	for (int i = 0; i < len; i++) {
		if (i == exclude)	continue;
		if (S.pop() != str[i]) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main() {
	char inputString[101];
	int checkIndex;
	int len;
	bool check1, check2;
	cout << "Enter strings(Program will be terminated, if cin receive EOF(input Ctrl+z if you use console(terminal)))" << endl;
	while (true) {
		checkIndex = -1;
		cin >> inputString;
		if (cin.eof()) {
			break;
		}
		Stack<char> S(len = strlen(inputString));
		for (int i = 0; i < len; i++) {
			S.push(inputString[i]);
		}

		for (int i = 0; i<len; i++) {
			if (S.pop() != inputString[i]) {
				check1 = checkPalindrome(inputString, i);
				check2 = checkPalindrome(inputString, len - 1 - i);
				if (check1 && check2) {
					checkIndex = i;
				}
				else if (!check1 && check2) {
					checkIndex = len - 1 - i;
				}
				else if (check1 && !check2) {
					checkIndex = i;
				}
				break;
			}
		}
		cout << checkIndex << endl;
		
	}
	return 0;
}