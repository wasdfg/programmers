#include <string>
#include <vector>
#include<iostream>

using namespace std;

void hanoi(vector<vector<int>>& answer,int n,int start,int end){
    if(n == 1){
        answer.push_back({start,end});
        return ;
    }
    else{
        hanoi(answer,n-1,start,6-start-end);
        answer.push_back({start,end});
        hanoi(answer,n-1,6-start-end,end);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer,n,1,3);
    return answer;
}