#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> word;
    for(int i = 0;i < keymap.size();i++){
        for(int j = 0;j < keymap[i].length();j++){
            if(word[keymap[i][j]] == 0){
                word[keymap[i][j]] = j+1;
            }
            else{
                word[keymap[i][j]] = min(word[keymap[i][j]],j+1);
            }
        }
    }
    for(int i = 0;i < targets.size();i++){
        int check = 0;
        bool cant = 0;
        for(int j = 0;j < targets[i].length();j++){
            if(word[targets[i][j]] != 0){
                check+=word[targets[i][j]];
            }
            else{
                cant = 1;
            }
        }
        if(cant == 1){
            answer.push_back(-1);
        }
        else{
            answer.push_back(check);
        }
    }
    return answer;
}