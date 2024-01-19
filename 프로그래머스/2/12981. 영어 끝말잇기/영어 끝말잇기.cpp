#include <string>
#include <vector>
#include<set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> check;
    check.insert(words[0]);
    for(int i = 1;i < words.size();i++){
        if(check.find(words[i]) == check.end() && words[i-1][words[i-1].length()-1] == words[i][0]){
            check.insert(words[i]);
        }
        else{
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}