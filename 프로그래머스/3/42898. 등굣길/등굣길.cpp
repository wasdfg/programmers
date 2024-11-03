#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> home(n+1,vector<int>(m+1,0));
    for(int i = 0;i < puddles.size();i++){
        home[puddles[i][1]][puddles[i][0]] = -1;
    }
    home[1][1] = 1; 
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < m+1;j++){
            if(home[i][j] == -1){
                continue;
            }
            int x = 0;
            int y = 0;
            if(home[i-1][j] != -1){
                x = home[i-1][j] % 1000000007;
            }
            if(home[i][j-1] != -1){
                y = home[i][j-1] % 1000000007;
            }
            home[i][j] += (x + y) % 1000000007;
        }
    }
    answer = home[n][m] % 1000000007;
    return answer;
}