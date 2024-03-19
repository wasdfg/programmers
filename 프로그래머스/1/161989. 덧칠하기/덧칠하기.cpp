#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1,check = section[0];
    for(int i = 0;i < section.size();i++){
        if(check+m > section[i]){
            continue;
        }
        else{
            check = section[i];
            answer++;
        }
    }
    return answer;
}