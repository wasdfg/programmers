#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

bool cmp(const vector<int>& a,const vector<int>& b){
    return a.size() < b.size();
}

vector<int> solution(string s){
    vector<int> answer;
    vector<vector<int>> number;
    vector<int> tonum;
    char a;
    string num = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){
            num+=s[i];
        }
        if(s[i] == '}' && i != s.length()-1){
            tonum.push_back(stoi(num));
            num = "";
            number.push_back(tonum);
            tonum.clear();
        }  
        if(s[i] == ',' && s[i-1] != '}'){
            tonum.push_back(stoi(num));
            num = "";
        }
  
    }
    sort(number.begin(),number.end(),cmp);
    for(int i = 0;i < number.size();i++){

        for(int j = 0;j < number[i].size();j++){
            if(find(answer.begin(),answer.end(),number[i][j]) == answer.end()){
                answer.push_back(number[i][j]);
            }
        }
    }
    return answer;
}