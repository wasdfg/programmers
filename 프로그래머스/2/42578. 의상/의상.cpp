#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> wear;
    for(int i = 0;i < clothes.size();i++){
        if(wear[clothes[i][1]] == 0){
            wear[clothes[i][1]] = 1;
        }
        else{
            wear[clothes[i][1]]++;
        }
    }
    for(auto iter : wear){
	    answer *= iter.second+1;
    }
    answer--;
    return answer;
}