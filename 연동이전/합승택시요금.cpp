#include <string>
#include <vector>
#include<iostream>

using namespace std;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> route(n,vector<int>(n,100001));
    for(int i = 0;i < n;i++){
        route[i][i] = 0;
    }
    for(int i = 0;i < fares.size();i++){
            route[fares[i][0]-1][fares[i][1]-1] = fares[i][2];
            route[fares[i][1]-1][fares[i][0]-1] = fares[i][2];
    }
    int answer = 100001;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){
                route[j][k] = min(route[j][k], route[j][i] + route[i][k]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        int total = route[s-1][i] + route[i][a-1] + route[i][b-1];
        answer = min(answer, total);
    }
    return answer;
}
