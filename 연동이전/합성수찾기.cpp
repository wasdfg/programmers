#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> prime(n+1,true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2;i * i <= n;i++){
        for(int j = 2;j *i <= n;j++){
            prime[i*j] = false;
        }
    }
    int answer = 0;
    for(int i = 2; i <= n;i++){
        if(prime[i] == false)
            answer++;
    }
    return answer;
}
