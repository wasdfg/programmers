#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num[100001] = {0,1,0,};
    for(int i = 2;i < 100001;i++){
        num[i] = ((num[i-1] % 1234567) + (num[i-2] % 1234567)) % 1234567; 
    }
    answer = num[n];
    return answer;
}