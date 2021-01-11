#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool check1 = false, check2;
    for(int i=0;i<words.size();i++){
        if(words[i].length() <= 1){
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            check1 = true;
            break;
        }
        else if(i >= 1 && words[i-1].at(words[i-1].size()-1) != words[i].at(0)){
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            check1 = true;
            break;
        }
        else{
            check2 = false;
            for(int j=0;j<i;j++){
                if(words[i].compare(words[j])==0){
                    check2 = true;
                    break;
                }
            }
            if(check2 == true){
                answer.push_back((i%n)+1);
                answer.push_back((i/n)+1);
                check1 = true;
                break;
            }
        }
    }
    if(check1 == false){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main(){

    return 0;
}