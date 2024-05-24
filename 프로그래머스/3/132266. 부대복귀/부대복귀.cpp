#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> location[n+1];
    for(int i = 0;i < roads.size();i++){
        location[roads[i][0]].push_back(roads[i][1]);
        location[roads[i][1]].push_back(roads[i][0]);
    }
    for(int i = 0;i < sources.size();i++){
        queue<pair<int,int>> togo;
        vector<bool> visited(n+1,0);
        togo.push({sources[i],0});
        visited[sources[i]] = 1;
        bool cant = true;
        while(!togo.empty()){
            int now = togo.front().first;
            int cost = togo.front().second;
            togo.pop();
            if(destination == now){
                answer.push_back(cost);
                cant = false;
                break;
            }
            for(int j = 0;j < location[now].size();j++){
                if(visited[location[now][j]] == 0){
                    togo.push({location[now][j],cost+1});
                    visited[location[now][j]] = 1;
                }
            }
        }
        if(cant == true){
            answer.push_back(-1);
        }
    }
    return answer;
}