#include <bits/stdc++.h>

using namespace std;

vector<string>split(string input, char d){
    vector<string> ret;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, d)) {
        ret.push_back(temp);
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <string> playInfo;
    vector <string> timeInfo1 , timeInfo2;
    vector <char> convert1, convert2;

    int minute;
    bool check;

    int len1 = m.length(), len2;

    for(int i=0;i<len1;i++){
        if(m[i+1] == '#'){
           convert1.push_back(tolower(m[i]));
           i++;
        }
        else convert1.push_back(m[i]);
    }
    
    
    

    for(int i=0;i<musicinfos.size();i++){
        playInfo = split(musicinfos[i],',');
        timeInfo1 = split(playInfo[0],':');
        timeInfo2 = split(playInfo[1],':');
        minute = (stoi(timeInfo2[0])-stoi(timeInfo1[0]))*60 + stoi(timeInfo2[1])-stoi(timeInfo1[1]);

        convert2.clear();

        len2 = playInfo[3].length();

        for(int j=0;j<len2;j++){
            if(playInfo[3][j+1] == '#'){
                convert2.push_back(tolower(playInfo[3][j]));
                j++;
            }
            else convert2.push_back(playInfo[3][j]);
        }

        for(int t=0; t<minute; t++){
            check = true;
            for(int k=0;k<convert1.size();k++){
                if(convert1[k] != convert2[(t+k)%convert2.size()]){
                    check = false;
                    break;
                }
            }
            if(check == true){
                answer = playInfo[2];
                return answer;
            }
        }

    }

    return answer;
}

int main(){

}