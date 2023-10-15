#include <string>
#include<iostream>
#include<set>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int> high;
    for(int i = 0;i < score.size();i++){
    if(high.size() < k){
        high.insert(score[i]);
        answer.push_back(*high.begin());
    }
    else{
        if(score[i] > *high.begin()){
            multiset<int>::iterator it = high.find(*high.begin());
            high.erase(it);
            high.insert(score[i]);
            answer.push_back(*high.begin());
        }
        else{
            answer.push_back(*high.begin());
        }
    }
    }
    return answer;
}