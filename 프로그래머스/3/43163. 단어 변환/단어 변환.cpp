#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0,len = begin.length();
    vector<bool> visited(words.size(),0);
    queue<pair<string,int>> togo;
    togo.push({begin,0});
    while(!togo.empty()){
        string a = togo.front().first;
        int cost = togo.front().second;
        togo.pop();
        if(a == target){
            answer = cost;
            break;
        }
        for(int i = 0;i < words.size();i++){
            int count = 0;
            for(int j = 0;j < len;j++){
                if(count >= 2){
                    break;
                }
                if(a[j] != words[i][j]){
                    count++;
                }
            }
            if(count == 1 && visited[i] == 0){
                visited[i] = 1;
                togo.push({words[i],cost+1});
            }
        }
    }
    return answer;
}