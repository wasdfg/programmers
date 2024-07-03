#include <string>
#include <vector>
#include<map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> cost;
    for(int i = 0;i < name.size();i++){
        cost[name[i]] = yearning[i];
    }
    for(int i = 0;i < photo.size();i++){
        int mem = 0;
        for(int j = 0;j < photo[i].size();j++){
            mem+=cost[photo[i][j]];
        }
        answer.push_back(mem);
    }
    return answer;
}