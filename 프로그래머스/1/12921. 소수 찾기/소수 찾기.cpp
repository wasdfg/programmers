#include <string>
#include <vector>

using namespace std;

vector<int> prime(1000001,1);
vector<int> dp(1000001,0);

int solution(int n) {
    int answer = 0,check = 0;
    prime[1] = 0;
    for(int i = 2;i*i <= 1000000;i++){
        for(int j = 2;j*i <= 1000000;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = 2;i <= 1000000;i++){
        if(prime[i] == 1){
            dp[i] = ++check;
        }
        else{
            dp[i] = check;
        }
    }
    answer = dp[n];
    return answer;
}