#include <string>
#include <vector>
#include<stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0;i < s.length();i++){
        if(i > 0){
            char a = s.front();
            s.erase(s.begin(),s.begin()+1);
            s.push_back(a);
        }
        stack<char> tmp;
        for(int j = 0;j < s.length();j++){
            if(tmp.empty()){
                tmp.push(s[j]);
            }
            else{
                if(tmp.top() == '(' && s[j] == ')'){
                    tmp.pop();
                }
                else if(tmp.top() == '[' && s[j] == ']'){
                    tmp.pop();
                }
                else if(tmp.top() == '{' && s[j] == '}'){
                    tmp.pop();
                }
                else{
                    tmp.push(s[j]);
                }
            }
        }
        if(tmp.empty()){
            answer++;
        }
    }
    return answer;
}