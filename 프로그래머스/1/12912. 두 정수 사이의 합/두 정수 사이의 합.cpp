#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long x = a,y = b;
    if(x > y){
        swap(x,y);
    }
    answer = (y-x+1)*(x+y)/2;
    return answer;
}