#include <vector>
#include<iostream>
#include<cstring>

using namespace std;
bool visited[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0}; 

int dfs(int m,int n,int x,int y,vector<vector<int>> picture){
    visited[x][y] = true;
    int bigone = 1;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n && picture[x+dx[i]][y+dy[i]] == picture[x][y]){
            if(visited[x+dx[i]][y+dy[i]] == false){
                bigone+=dfs(m,n,x+dx[i],y+dy[i],picture);
            } 
        } 
    }
    return bigone;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    memset(visited,0,sizeof(visited));
    for(int i = 0;i < picture.size();i++){
        for(int j = 0;j < picture[i].size();j++){
            if(picture[i][j] != 0 && visited[i][j] == false){
                max_size_of_one_area = max(max_size_of_one_area,dfs(m,n,i,j,picture));
                number_of_area++;
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}