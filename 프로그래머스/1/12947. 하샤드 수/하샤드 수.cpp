#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int num = 0,check = x;
    while(check){
        num+=check%10;
        check/=10;
    }
    if(x % num != 0){
        answer = false; 
    }
    return answer;
}