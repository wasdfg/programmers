#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string s){
    vector<int> allnum;
    string answer = "";
    string copy = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] == ' ')
            continue;
        if(isdigit(s[i]) == 1){
            copy+=s[i];
            if(s[i+1] == ' ' || (i == s.length()-1)){
            allnum.push_back(stoi(copy));
            copy="";
        }
        }
        else if(s[i] == '-'){
            copy+='-';
        }
    }
    stable_sort(allnum.begin(),allnum.end());
    answer+=to_string(allnum[0]);
    answer+=" ";
    answer+=to_string(allnum[allnum.size()-1]);
    return answer;
}