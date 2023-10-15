#include <string>
#include<iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board){//0일때만 -1로 바꾸면 됨
    int answer = 0;
    int sized = board[0].size();
    for(int i = 0;i < sized;i++){
        for(int j = 0;j < sized;j++){
            if(board[i][j] == 1){
                for(int k = -1;k <= 1;k++){
                    for(int l = -1;l <= 1;l++){
                        if((k == 0 && l == 0) || (i+k < 0 || j+l < 0) || (i+k >= sized || j+l >= sized))
                            continue;
                        if(board[i+k][j+l] == 0){
                            board[i+k][j+l] = -1;
                        }
                    }
                }
            }
        }
    }
     for(int i = 0;i < sized;i++){
        for(int j = 0;j < sized;j++){
        if(board[i][j] == 0)
            answer++;
        }
     }
    return answer;
}