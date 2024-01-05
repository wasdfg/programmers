#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int cmp(string a,string b){
    return a + b > b + a;
}

string solution(vector<int> numbers){
    vector<string> s;
    string answer = "";
    for(int i = 0;i < numbers.size();i++){
        s.push_back(to_string(numbers[i]));
    }
    stable_sort(s.begin(),s.end(),cmp);
    for(int i = 0;i < s.size();i++){
        answer+=s[i];
    }
    if(answer[0] == '0'){
        return "0";
    }
    return answer;
}