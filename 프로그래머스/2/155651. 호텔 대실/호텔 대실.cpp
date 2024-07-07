#include <string>
#include <vector>
#include<iostream>
using namespace std;


int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int a,b;
    vector<int> cost(1450,0);
    for(int i = 0;i < book_time.size();i++){
        a = stoi(book_time[i][0].substr(0,2))*60+stoi(book_time[i][0].substr(3,2));
        b = stoi(book_time[i][1].substr(0,2))*60+stoi(book_time[i][1].substr(3,2))+10;
        for(int j = a;j < b;j++){
            cost[j]++;
        }
    }
    for(int i = 0;i < 1440;i++){
        answer = max(answer,cost[i]);
    }
    return answer;
}