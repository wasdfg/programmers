#include <string>
#include <vector>
#include<stack>
#include<iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> tmp;
    for(int i = 0;i < order.size();i++){
        tmp.push(i+1);
        while(!tmp.empty() && tmp.top() == order[answer]){
            tmp.pop();
            answer++;
        }
    }
    return answer;
}