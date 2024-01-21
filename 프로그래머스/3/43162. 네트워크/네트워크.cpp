#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<bool>> check(n,vector<bool>(n,0));
    vector<bool> visited(n,0);
    queue<int> togo;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            check[i][j] = computers[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(check[i][j] == 1 && visited[i] == 0){
                visited[i] = 1;
                togo.push({i});
                while(!togo.empty()){
                    int x = togo.front();
                    togo.pop();
                    for(int k = 0;k < n;k++){
                        if(check[x][k] == 1 && visited[k] == 0){
                            visited[k] = 1;
                            togo.push(k);
                        }
                    }
                }
                answer++;
            }
        }
    }
    return answer;
}