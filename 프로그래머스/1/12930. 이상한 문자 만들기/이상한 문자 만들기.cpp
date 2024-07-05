#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string x = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] == 32){
            for(int j = 0;j < x.length();j++){
                if(j % 2 == 0){
                    answer+=toupper(x[j]);
                }
                else{
                    answer+=tolower(x[j]);
                }
            }
            answer+=" ";
            x = "";
        }
        else{
            x+=s[i];
        }
    }
    for(int j = 0;j < x.length();j++){
        if(j % 2 == 0){
            answer+=toupper(x[j]);
        }
        else{
            answer+=tolower(x[j]);
        }
    }
    return answer;
}