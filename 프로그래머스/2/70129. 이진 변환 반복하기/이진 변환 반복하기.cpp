#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(string s) {
    int count = 0,remove = 0;
    vector<int> answer;
    while(s.length() != 1){
        string check = "";
        for(int i = 0;i < s.length();i++){
            if(s[i] == '0'){
                remove++;
            }
            else{
                check+="1";
            }
        }
        int x = check.length();
        string tmp = "";
        while(x != 0){
            if(x%2 == 0){
                tmp+="0";
            }
            else{
                tmp+="1";
            }
            x/=2;
        }
        s = tmp;
        count++;
    }
    answer.push_back(count);
    answer.push_back(remove);
    return answer;
}