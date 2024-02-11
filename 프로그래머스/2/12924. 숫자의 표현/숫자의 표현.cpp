#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> check;
    for(int i = 1;i*i <= n*2;i++){
        if(n*2 % i == 0){
            check.push_back(max(n*2/i-i,i-n*2/i));
        }
    }
    for(int i = 0;i < check.size();i++){
       if((check[i]+1) % 2 == 0){
           answer++;
       }
    }
    return answer;
}