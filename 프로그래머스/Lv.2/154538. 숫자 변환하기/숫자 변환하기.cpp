#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int x, int y, int n){
    vector<int> dp(1000001,1000001);
    int answer = 0;
    dp[x] = 0;
    for(int i = x;i <= y;i++){
        if(i * 3 <= y){
            dp[i*3] = min(dp[i]+1,dp[i*3]);
        }
        if(i * 2 <= y){
            dp[i*2] = min(dp[i]+1,dp[i*2]);
        }
        if(i + n <= y){
            dp[i+n] = min(dp[i]+1,dp[i+n]);
        }
    }
    answer = dp[y];
    if(answer == 1000001){
        answer = -1;
    }
    return answer;
}