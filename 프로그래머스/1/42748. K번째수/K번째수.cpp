#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sub;
    for(int i = 0;i < commands.size();i++){
        sub = vector<int> ();
        for(int j = commands[i][0]-1;j < commands[i][1];j++){
            sub.push_back(array[j]);
        }
        stable_sort(sub.begin(),sub.end());
        answer.push_back(sub[commands[i][2]-1]);
    }
    return answer;
}