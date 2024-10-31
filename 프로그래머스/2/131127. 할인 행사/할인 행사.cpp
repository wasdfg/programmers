#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0,start = 0,end = 9,check = 0;
    vector<int> tmp(number.size(),0);
    for(int i = 0;i < 10;i++){
       for(int j = 0;j < want.size();j++){
           if(want[j] == discount[i]){
               tmp[j]++;
               break;
           }
       } 
    }
    for(int i = 0;i < number.size();i++){
        if(number[i] == tmp[i]){
            check++;
        }
    }
    if(check == number.size()){
        answer++;
    }
    while(end < discount.size()){
        check = 0;
        start++;
        end++;
        if(end == discount.size()){
            break;
        }
        for(int i = 0;i < want.size();i++){
            if(want[i] == discount[start-1]){
                tmp[i]--;
                break;
            }
        }
        for(int i = 0;i < want.size();i++){
            if(want[i] == discount[end]){
                tmp[i]++;
                break;
            }
        }
        for(int i = 0;i < number.size();i++){
            if(number[i] == tmp[i]){
                check++;
            }
        }
        if(check == number.size()){
        answer++;
        }
    }
    return answer;
}