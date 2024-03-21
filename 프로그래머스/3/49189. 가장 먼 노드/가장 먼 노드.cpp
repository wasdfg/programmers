#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0,check = 1;
    vector<int> dist(n,50001);
    vector<int> node[n];
    vector<bool> visited(n,0);
    queue<pair<int,int>> togo;
    togo.push({0,0});
    visited[0] = 1;
    if(n == 2){
        answer = 1;
    }
    else{
        for(int i = 0;i < edge.size();i++){
            node[edge[i][0]-1].push_back(edge[i][1]-1);
            node[edge[i][1]-1].push_back(edge[i][0]-1);
        }
        for(int i = 0;i < n;i++){
            sort(node[i].begin(),node[i].end());
        }
        while(!togo.empty()){
            int now = togo.front().first;
            int cost = togo.front().second;
            togo.pop();
            for(int i = 0;i < node[now].size();i++){
                if(cost+1 < dist[node[now][i]] && visited[node[now][i]] == 0){
                    visited[node[now][i]] = 1;
                    dist[node[now][i]] = cost+1;
                    togo.push({node[now][i],cost+1});
                }
            }
        }
    }
    for(int i = 1;i < n;i++){
        if(dist[i] == check){
            answer++;
        }
        else if(dist[i] > check && dist[i] != 50001){
            check = dist[i];
            answer = 1;
        }
    }
    return answer;
}