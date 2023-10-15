#include <string>
#include<algorithm>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<string> babbling){
    int answer = 0;
    for(int i = 0;i < babbling.size();i++){
        bool check = true;
       for(int j = 0;j < babbling[i].size();j++){
        if(babbling[i].substr(j,3) == "aya"){
            j+=2;
        }
        else if(babbling[i].substr(j,3) == "woo"){
            j+=2;
        }
        else if(babbling[i].substr(j,2) == "ye"){
            j+=1;
        }
        else if(babbling[i].substr(j,2) == "ma"){
            j+=1;
        }
        else{
            check = false;
            break;
        }
       }
       if(check == true){
           answer++;
       } 
    }
    return answer;
}