#include <string>
#include <vector>
#include<map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0,check;
    bool able;
    map<char,int> seq;
    for(int i = 0;i < skill.length();i++){
            seq[skill[i]] = i+1;
    }
    for(int i = 0;i < skill_trees.size();i++){
        able = true;
        check = 1;
        for(int j = 0;j < skill_trees[i].length();j++){
            if(seq[skill_trees[i][j]] != 0){
                if(seq[skill_trees[i][j]] == check){
                    check++;
                }
                else{
                    able = false;
                    break;
                }
            }
        }
        if(able){
            answer++;
        }
    }
    return answer;
}