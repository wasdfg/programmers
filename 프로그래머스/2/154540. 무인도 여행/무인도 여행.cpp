#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<int>> zido(maps.size(),vector<int> (maps[0].length(),0));
    vector<vector<bool>> visited(maps.size(),vector<bool> (maps[0].length(),0));
    queue<pair<int,int>> togo;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int area;
    for(int i = 0;i < maps.size();i++){
        for(int j = 0;j < maps[0].length();j++){
            if(maps[i][j] == 'X'){
                zido[i][j] = 0;
            }
            else{
                zido[i][j] = maps[i][j]-48;
            }
        }
    }
    for(int i = 0;i < maps.size();i++){
        for(int j = 0;j < maps[0].length();j++){
            if(zido[i][j] != 0 && visited[i][j] == 0){
                area = 0;
                area+=zido[i][j];
                visited[i][j] = 1;
                togo.push({i,j});
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < maps.size() && y+dy[k] >= 0 && y+dy[k] < maps[0].length() && zido[x+dx[k]][y+dy[k]] != 0 && visited[x+dx[k]][y+dy[k]] == 0){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            area+=zido[x+dx[k]][y+dy[k]];
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                answer.push_back(area);
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}