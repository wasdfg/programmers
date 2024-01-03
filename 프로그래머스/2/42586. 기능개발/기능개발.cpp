#include <string>
#include <vector>
#include<queue>
#include<cmath>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer;
    deque<int> copy;
    deque<int> scopy;
    int count,days;
    for(int i = 0;i < progresses.size();i++){
        copy.push_back(progresses[i]);
        scopy.push_back(speeds[i]);
    }
    while(!copy.empty()){
        days = ceil((double)(100 - copy.front()) / scopy.front());
        count = 0;
        for(int i = 0;i < copy.size();i++){
            copy[i] += (days*scopy[i]);
        }
        while(!copy.empty()){
            if(copy.front() < 100){
                break;
            }
            else{
                copy.pop_front();
                scopy.pop_front();
                count++;
            }
        }
        answer.push_back(count);
    }
    return answer;
}