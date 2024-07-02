#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer = 0,three = 0,sam = 1;
    while(n > 0){
        three+=(n%3);
        n/=3;
        three*=10;
    }
    three/=10;
    while(three > 0){
        answer+=((three%10)*sam);
        sam*=3;
        three/=10;
    }
    return answer;
}