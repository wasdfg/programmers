#include <string>
#include <vector>
using namespace std;

int solution(int n){
    int answer = 0;
    int onecount = 0;
    for(int i = 0;i <= 20;i++){
        if(n & 0x01<<i){
            onecount++;
        }
    }
    while(1){
        n++;
        int check = 0;
        for(int i = 0;i <= 20;i++){
            if(n & 0x01<<i){
                check++;
            }
        }
        if(check == onecount){
            answer = n;
            break;
        }
    }
    return answer;
}