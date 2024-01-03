#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> priorities, int location){
    queue<int> a;
    for(int i = 0;i < priorities.size();i++){
        a.push(priorities[i]);
    }
    stable_sort(priorities.begin(),priorities.end(),greater<int>());
    int answer = 0;
    while(1){
        if(a.front() == priorities[0]){
            answer++;
            a.pop();
            priorities.erase(priorities.begin());
            if(location == 0){
                return answer;
            }
            else{
                location--;
            }
        }
        else{
            a.emplace(a.front());
            a.pop();
            location--;
            if(location < 0){
                location = a.size()-1; 
            }
        }
    }
    return answer;
}