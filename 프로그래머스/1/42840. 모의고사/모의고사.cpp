#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    int x = 0,y = 0,z = 0;
    for(int i = 0;i < answers.size();i++){
        if(answers[i] == one[i % 5]){
            x++;
        }
        if(answers[i] == two[i % 8]){
            y++;
        }
        if(answers[i] == three[i % 10]){
            z++;
        }
    }
    int t = max({x,y,z});
    if(t == x){
        answer.push_back(1);
    }
    if(t == y){
        answer.push_back(2);
    }
    if(t == z){
        answer.push_back(3);
    }
    return answer;
}