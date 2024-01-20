#include <string>
#include <vector>
#include<set>
#include<iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion){
    string answer = "";
    multiset<string> complete;
    for(int i = 0; i < participant.size();i++){
        complete.insert(participant[i]);
    }
    for(int i = 0;i <completion.size();i++){
        if(complete.find(completion[i]) != complete.end()){
            complete.erase(complete.find(completion[i]));
        }
    }
    for(const auto& a :complete){
        answer+=a;
    }
    return answer;
}