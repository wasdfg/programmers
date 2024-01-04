#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i = 1; i < n+1;i++){
        if(i % money[0] == 0){
            dp[i] = 1;
        } 
    }
    
    for(int i = 1; i < money.size();i++){
        for(int j = 0;j < n+1;j++){
            if(j >= money[i]){
                dp[j] = (dp[j] + dp[j-money[i]]) % 1000000007;
            }
        }
    }
    answer = dp[n];
    return answer;
}