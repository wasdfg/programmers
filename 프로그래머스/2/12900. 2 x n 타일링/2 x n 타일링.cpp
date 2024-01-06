#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[60001] = {0,};
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < 60001;i++){
        dp[i] = ((dp[i-1] % 1000000007) + (dp[i-2] % 1000000007)) % 1000000007;
    }
    answer = dp[n];
    return answer;
}