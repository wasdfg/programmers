#include <vector>
#include <string>
#include<algorithm>
#include<iostream>
#include<cctype>

using namespace std;

int solution(string str1, string str2) {
    long long answer = 0;
    vector<string> one;
    vector<string> two;
    for(char &ch:str1){
        ch = tolower(ch);
    }
    for(char &ch:str2){
        ch = tolower(ch);
    }
    for(int i = 0;i < str1.length()-1;i++){
        string s = "";
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            s+=str1[i];
            s+=str1[i+1];
        }
        else{
            continue;
        }
        one.push_back(s);
    }
    for(int i = 0;i < str2.length()-1;i++){
        string s = "";
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            s+=str2[i];
            s+=str2[i+1];
        }
        else{
            continue;
        }
        two.push_back(s);
    }
    stable_sort(one.begin(),one.end());
    stable_sort(two.begin(),two.end());
    vector<string> unionlen(one.size() + two.size());
    vector<string> intersaction(one.size() + two.size());
    auto iter = set_union(one.begin(), one.end(), two.begin(), two.end(), unionlen.begin());
    unionlen.erase(iter, unionlen.end());
    iter = set_intersection(one.begin(), one.end(), two.begin(), two.end(), intersaction.begin());
    intersaction.erase(iter,intersaction.end());
    if(one.size() == 0 && two.size() == 0){
        return 65536;
    }
    answer = 65536 * intersaction.size() / unionlen.size();
    return answer;
}