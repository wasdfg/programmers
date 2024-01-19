#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s){
    int answer = 0;
    stack<char> zzak;
    if(s.empty() || s.size() % 2 != 0){
        return answer;
    }
    else{

        for(int i = 0;i < s.size();i++){
            if(zzak.empty() || zzak.top() != s[i]){
                zzak.push(s[i]);
            }
            else{
                zzak.pop();
            }
        }
    }
    if(zzak.empty()){
        answer = 1;
    }
    return answer;
}